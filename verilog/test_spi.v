`timescale 1ns / 1ps

module test_spi;

	// Inputs
	reg clk;
	reg miso;
	reg[7:0] data_in;
	reg ready_send;
	reg rst;

	// Outputs
	wire mosi;
	wire sclk;
	wire ss;
	wire[7:0] data_out;

	// Instantiate the Unit Under Test (UUT)
	spi uut (
    .clk(clk), 
    .miso(miso), 
    .data_in(data_in), 
    .ready_send(ready_send), 
    .rst(rst), 
    .mosi(mosi), 
    .sclk(sclk), 
    .ss(ss), 
    .data_out(data_out)
    );



	initial begin
		// Initialize Inputs
		clk = 0;
		miso = 0;
		rst = 1;
		// Wait for two clocks for the global reset to finish
		@(posedge clk);
		@(posedge clk);
		
		rst = 0;
		data_in = 8'b00010011; // 13
		ready_send = 1;
		@(ss == 1);
		ready_send = 0;
		#1;
		// 37 8'b00110111
		@(negedge sclk);
		miso = 0;
		@(negedge sclk);
		miso = 0;
		@(negedge sclk);
		miso = 1;
		@(negedge sclk);
		miso = 1;
		@(negedge sclk);
		miso = 0;
		@(negedge sclk);
		miso = 1;
		@(negedge sclk);
		miso = 1;
		@(negedge sclk);
		miso = 1;
			
		@(posedge clk);
		@(posedge clk);
		@(posedge clk);
		$finish;
        
		// Add stimulus here

	end
	
	always
	#5 clk = ! clk;
      
endmodule

