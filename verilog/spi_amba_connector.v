`timescale 1ns / 1ps

module spi_amba_connector(
    input clk,
    input rst,
	 
    input hwrite,
    input [31:0] hwdata,
    input [31:0] haddr,
    input hsel,
	 output reg [31:0] hrdata,
    
    input [7:0] spi_data_out,
    input spi_busy,
    output reg [7:0] spi_data_in,
    output reg spi_ready_send
    );
	 
reg [7:0] spi_data_out_reg;

always @(posedge clk) begin
	if (rst) begin
		hrdata <= 0;
		spi_data_in <= 0;
		spi_ready_send <= 0;
	end
	if (hsel) begin
		if ((haddr == 'h0000) && hwrite && !spi_busy) begin
			spi_data_in <= hwdata[7:0];
			spi_ready_send <= 1;
		end else if ((haddr == 'h0004) && !hwrite) begin
			hrdata[8] <= spi_busy;
			hrdata[7:0] <= spi_data_out_reg;
		end
	end
end

always @(negedge clk) begin
	if (!spi_busy) begin
		spi_data_out_reg <= spi_data_out;
	end else begin
		spi_ready_send <= 0;
	end
end

endmodule
