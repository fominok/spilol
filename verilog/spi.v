`timescale 1ns / 1ps

module spi(
    input clk,                 // Тактовый сигнал с процессора
    input miso,                // Master in slave out
	 input[7:0] data_in,        // Данные для передачи от процессора
	 input ready_send,          // Данные положены в data-in и готовы к отправке
	 input rst,
    output reg mosi,           // Master out slave in
    output reg sclk = 0,       // Тактовый сигнал к рабам
    output reg ss,             // Slave select
	 output reg[7:0] data_out   // Принятые данные от раба
    );

localparam IDLE = 0;
localparam EXGE = 1;

reg[7:0] state;
reg[7:0] counter;
reg[7:0] data_in_reg;
reg      clk_tmp = 0;

always @(posedge clk) begin
	clk_tmp <= !clk_tmp;
	if (clk_tmp) begin
		sclk <= !sclk;
	end
end

always @(posedge sclk) begin
	if (rst) begin
		state <= IDLE;
		data_out <= 0; // говно какое-то 
	end
	case(state)
		IDLE: begin
			mosi <= 'bz;
			ss <= 1;
			if(ready_send) begin
				counter <= 8;
				ss <= 0;
				state <= EXGE;
				data_in_reg <= data_in;
			end
		end
		EXGE: begin
			if (counter == 0) begin
				mosi <= 'bz;
				ss <= 1;
				state <= IDLE;
			end else begin
				mosi <= data_in_reg[counter - 1]; // send
				counter <= counter - 1;
			end
		end
	endcase
end

always @(negedge sclk) begin
	if (state == EXGE) begin
		data_out[counter] <= miso; // receive
	end
end

endmodule
