`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:07:38 10/10/2016
// Design Name:   simple
// Module Name:   /home/yolo/fpga/spilol/test_simple.v
// Project Name:  spilol
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: simple
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_simple;

	// Inputs
	reg A;
	reg B;
	reg C;
	reg D;

	// Outputs
	wire E;
	wire F;

	// Instantiate the Unit Under Test (UUT)
	simple uut (
		.E(E), 
		.F(F), 
		.A(A), 
		.B(B), 
		.C(C), 
		.D(D)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		C = 0;
		D = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
	
	always
		#5 clk = ! clk;
      
endmodule

