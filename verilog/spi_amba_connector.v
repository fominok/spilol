`timescale 1ns / 1ps

module spi_amba_connector(
    input             clk,
    input             rst,

    input             hwrite,
    input      [31:0] hwdata,
    input      [31:0] haddr,
    input             hsel,
    output     [31:0] hrdata,

    input      [ 7:0] spi_data_out,
    input             spi_busy,
    output reg [ 7:0] spi_data_in,
    output reg        spi_ready_send
);

reg [7:0] spi_data_out_reg;

assign hrdata = {{25'b0, spi_busy, spi_busy ? spi_data_out_reg : spi_data_out}};

always @(posedge clk) begin
    if (rst) begin
        spi_data_in <= 0;
        spi_ready_send <= 0;
    end else if (spi_ready_send && spi_busy) begin
        spi_ready_send <= 0;
    end else if (!spi_ready_send && !spi_busy) begin
        if (hsel && haddr == 'h0000 && hwrite) begin
            spi_data_in <= hwdata[7:0];
            spi_ready_send <= 1;
        end
    end
end

endmodule
