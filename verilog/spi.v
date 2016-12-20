
`timescale 1ns / 1ps

module spi #(
    parameter clk_divisor=8    // SCLK shall be this many
                               //     times slower than CLK;
                               //     can only be an even number.
)
(
    input           clk,        // Processor clock
    input           rst,        // Processor reset

    input     [7:0] data_in,    // Data to be transferred
    output reg[7:0] data_out,   // Received data
    input           ready_send, // Initialize transfer
    output          busy,       // Transaction is in progress

    input           miso,       // Master in slave out
    output          mosi,       // Master out slave in
    output          sclk,       // SPI clock
    output          ss          // Slave select
);

reg[ 3:0] sctr;
reg[ 7:0] data_in_reg;

reg[31:0] ctr;

assign ss   = sctr == 0;
assign sclk = !sctr[0] || ss;
assign mosi = data_in_reg[sctr >> 1];
assign busy = !ss;

always @(posedge clk) begin
    if (rst) begin
        sctr        <= 0;
        ctr         <= 0;
        data_out    <= 0;
    end else if (ready_send && !sctr) begin
        data_in_reg <= data_in;
        sctr        <= 15;
        ctr         <= 0;
    end else if (sctr && ctr + 1 == clk_divisor >> 1) begin
        ctr <= 0;
        if (sctr[0])
            data_out[sctr >> 1] <= miso;
        sctr <= sctr - 1;
    end else if (sctr) begin
        ctr <= ctr + 1;
    end
end

endmodule
