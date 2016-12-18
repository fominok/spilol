`timescale 1ns / 1ps

module test_spi;

// Inputs
reg        clk;
reg        miso;
//reg[7:0]   data_in;
//reg        ready_send;
reg        rst;
reg 		   hwrite;
reg[31:0]  hwdata;
reg[31:0]  haddr;
reg 	     hsel;

// Outputs
wire       mosi;
wire       sclk;
wire       ss;
//wire      busy;
//wire[7:0] data_out;
wire[31:0] hrdata;

// amba_connector - - spi
wire [7:0] spi_data_out;
wire       spi_busy;
wire [7:0] spi_data_in;
wire       spi_ready_send;

// Instantiate the Unit Under Test (UUT)
spi uut (
    .clk            (clk           ),
    .miso           (miso          ),
    .data_in        (spi_data_in   ),
    .ready_send     (spi_ready_send),
    .rst            (rst           ),
    .mosi           (mosi          ),
    .sclk           (sclk          ),
    .ss             (ss            ),
    .busy           (spi_busy      ),
    .data_out       (spi_data_out  )
);

spi_amba_connector amba_uut (
    .clk            (clk            ),
    .rst            (rst            ),
    .hwrite         (hwrite         ),
    .hwdata         (hwdata         ),
    .haddr          (haddr          ),
    .hsel           (hsel           ),
	 .hrdata         (hrdata         ),
    .spi_data_out   (spi_data_out   ),
    .spi_busy       (spi_busy       ),
    .spi_data_in    (spi_data_in    ),
    .spi_ready_send (spi_ready_send)
);



initial begin
    // Initialize Inputs
    clk  = 0;
    miso = 0;
    rst  = 1;
    // Wait for two clocks for the global reset to finish
    @(posedge clk);
    @(posedge clk);

    rst        = 0;
	 hwrite = 1;
	 hwdata = 'h00000013;
	 haddr = 'h00000000;
	 hsel = 1;
	 @(spi_busy == 1);
	 miso = 0;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 1;
    @(negedge sclk); miso = 1;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 1;
    @(negedge sclk); miso = 1;
    @(negedge sclk); miso = 1;
	 hwrite = 0;
	 hsel=0;
	 #10;
	 haddr = 'h00000004;
	 hsel = 1;
	 #50;
	 hsel = 0;
     @(spi_busy == 0);
	 miso = 0;
	 hwrite = 1;
	 hwdata = 'h00000014;
	 haddr = 'h00000000;
	 hsel = 1;
	 @(spi_busy == 1);
	 miso = 1;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 1;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 0;
    @(negedge sclk); miso = 0;
	 #50;
	 hwrite = 0;
	 hsel=0;
	 @(spi_busy == 0);
	 #10;
	 haddr = 'h00000004;
	 hsel = 1;
	 #50;
	 hsel = 0;
   
    @(posedge clk);
    @(posedge clk);
    @(posedge clk);
    $finish;

end

always #5 clk = ! clk;

endmodule

