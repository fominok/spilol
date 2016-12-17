
`timescale 1ns / 1ps

module spi #(
    parameter clk_divisor=8    // SCLK shall be this times slower than CLK;
                               //     can only be an even number.
)
(
    input clk,                 // Processor clock
    input rst,                 // Processor reset

    input[7:0] data_in,        // Data to be transferred
    input ready_send,          // Initialize transfer
    output reg[7:0] data_out,  // Received data
    output busy,               // Transaction is in progress

    input      miso,           // Master in slave out
    output reg mosi,           // Master out slave in
    output     sclk,           // SPI clock
    output     ss              // Slave select
);

reg      enabled;
reg[2:0] pos_ctr;
reg[2:0] neg_ctr;
reg[7:0] data_in_reg;

reg[7:0] ctr;
reg      sclk_p;

assign ss = !enabled;
assign sclk = !sclk_p || ss;
assign busy = enabled;

always @(posedge clk) begin
    if (rst) begin
        ctr <= 0;
        data_out <= 0;
        enabled <= 0;
        data_in_reg <= 0;
        mosi <= 0;
        sclk_p <= 0;
        pos_ctr <= 0;
        neg_ctr <= 0;
    end else if (ready_send && !enabled) begin
        data_in_reg <= data_in;
        mosi <= data_in[7];
        pos_ctr <= 7;
        ctr <= 0;
        sclk_p <= 1;
    end else if (enabled && ctr + 1 == clk_divisor >> 1) begin
        ctr <= 0;
        if (sclk_p) begin
            sclk_p <= 0; // Negedge
            data_out[pos_ctr] <= miso;
            neg_ctr <= pos_ctr - 1;
        end else begin
            sclk_p <= 1; // Posedge
            if (neg_ctr == 7) begin
                enabled <= 0;
            end else begin
                pos_ctr <= neg_ctr;
                mosi <= data_in[neg_ctr];
            end
        end
    end else if (enabled) begin
        ctr <= ctr + 1;
    end
end

endmodule
