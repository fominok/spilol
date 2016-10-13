////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: spi_synthesis.v
// /___/   /\     Timestamp: Thu Oct 13 14:16:33 2016
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim spi.ngc spi_synthesis.v 
// Device	: xc7a100t-3-csg324
// Input file	: spi.ngc
// Output file	: /home/yolo/fpga/spilol/netgen/synthesis/spi_synthesis.v
// # of Modules	: 1
// Design Name	: spi
// Xilinx        : /home/yolo/flash/Xilinx/14.7/ISE_DS/ISE/
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module spi (
  clk, miso, ready_send, rst, mosi, sclk, ss, data_in, data_out
);
  input clk;
  input miso;
  input ready_send;
  input rst;
  output mosi;
  output sclk;
  output ss;
  input [7 : 0] data_in;
  output [7 : 0] data_out;
  wire data_in_7_IBUF_0;
  wire data_in_6_IBUF_1;
  wire data_in_5_IBUF_2;
  wire data_in_4_IBUF_3;
  wire data_in_3_IBUF_4;
  wire data_in_2_IBUF_5;
  wire data_in_1_IBUF_6;
  wire data_in_0_IBUF_7;
  wire sclk_OBUF_BUFG_8;
  wire miso_IBUF_9;
  wire ready_send_IBUF_10;
  wire ss_OBUF_19;
  wire state_FSM_FFd1_22;
  wire mosi_OBUF_23;
  wire data_out_7_24;
  wire data_out_6_25;
  wire data_out_5_26;
  wire data_out_4_27;
  wire data_out_3_28;
  wire data_out_2_29;
  wire data_out_1_30;
  wire data_out_0_31;
  wire \state[7]_ss_Select_15_o ;
  wire \state[7]_counter[7]_select_14_OUT<2> ;
  wire \state[7]_counter[7]_select_14_OUT<1> ;
  wire \state[7]_counter[7]_select_14_OUT<0> ;
  wire \state_FSM_FFd1-In ;
  wire \Mmux_counter[2]_data_in_reg[7]_Mux_4_o_4_46 ;
  wire \Mmux_counter[2]_data_in_reg[7]_Mux_4_o_3_47 ;
  wire mosi_rstpot_70;
  wire \state[7]_counter[7]_select_14_OUT<1>31_cepot ;
  wire data_in_reg_0_dpot_72;
  wire data_in_reg_1_dpot_73;
  wire data_in_reg_2_dpot_74;
  wire data_in_reg_3_dpot_75;
  wire data_in_reg_4_dpot_76;
  wire data_in_reg_5_dpot_77;
  wire data_in_reg_6_dpot_78;
  wire data_in_reg_7_dpot_79;
  wire sclk_OBUF_80;
  wire [7 : 0] data_in_reg;
  wire [2 : 0] counter;
  wire [7 : 0] _n0080;
  FD   counter_0 (
    .C(sclk_OBUF_BUFG_8),
    .D(\state[7]_counter[7]_select_14_OUT<0> ),
    .Q(counter[0])
  );
  FD   counter_1 (
    .C(sclk_OBUF_BUFG_8),
    .D(\state[7]_counter[7]_select_14_OUT<1> ),
    .Q(counter[1])
  );
  FD   counter_2 (
    .C(sclk_OBUF_BUFG_8),
    .D(\state[7]_counter[7]_select_14_OUT<2> ),
    .Q(counter[2])
  );
  FDE   data_in_reg_0 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_0_dpot_72),
    .Q(data_in_reg[0])
  );
  FDE   data_in_reg_1 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_1_dpot_73),
    .Q(data_in_reg[1])
  );
  FDE   data_in_reg_2 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_2_dpot_74),
    .Q(data_in_reg[2])
  );
  FDE   data_in_reg_3 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_3_dpot_75),
    .Q(data_in_reg[3])
  );
  FDE   data_in_reg_4 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_4_dpot_76),
    .Q(data_in_reg[4])
  );
  FDE   data_in_reg_5 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_5_dpot_77),
    .Q(data_in_reg[5])
  );
  FDE   data_in_reg_6 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_6_dpot_78),
    .Q(data_in_reg[6])
  );
  FDE   data_in_reg_7 (
    .C(sclk_OBUF_BUFG_8),
    .CE(\state[7]_counter[7]_select_14_OUT<1>31_cepot ),
    .D(data_in_reg_7_dpot_79),
    .Q(data_in_reg[7])
  );
  FD   ss_12 (
    .C(sclk_OBUF_BUFG_8),
    .D(\state[7]_ss_Select_15_o ),
    .Q(ss_OBUF_19)
  );
  FD   data_out_0 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[7]),
    .Q(data_out_0_31)
  );
  FD   data_out_1 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[6]),
    .Q(data_out_1_30)
  );
  FD   data_out_2 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[5]),
    .Q(data_out_2_29)
  );
  FD   data_out_3 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[4]),
    .Q(data_out_3_28)
  );
  FD   data_out_4 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[3]),
    .Q(data_out_4_27)
  );
  FD   data_out_5 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[2]),
    .Q(data_out_5_26)
  );
  FD   data_out_6 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[1]),
    .Q(data_out_6_25)
  );
  FD   data_out_7 (
    .C(sclk_OBUF_BUFG_8),
    .D(_n0080[0]),
    .Q(data_out_7_24)
  );
  FD #(
    .INIT ( 1'b0 ))
  state_FSM_FFd1 (
    .C(sclk_OBUF_BUFG_8),
    .D(\state_FSM_FFd1-In ),
    .Q(state_FSM_FFd1_22)
  );
  LUT6 #(
    .INIT ( 64'hF0F0FF00CCCCAAAA ))
  \Mmux_counter[2]_data_in_reg[7]_Mux_4_o_4  (
    .I0(data_in_reg[0]),
    .I1(data_in_reg[1]),
    .I2(data_in_reg[3]),
    .I3(data_in_reg[2]),
    .I4(counter[0]),
    .I5(counter[1]),
    .O(\Mmux_counter[2]_data_in_reg[7]_Mux_4_o_4_46 )
  );
  LUT6 #(
    .INIT ( 64'hF0F0FF00CCCCAAAA ))
  \Mmux_counter[2]_data_in_reg[7]_Mux_4_o_3  (
    .I0(data_in_reg[4]),
    .I1(data_in_reg[5]),
    .I2(data_in_reg[7]),
    .I3(data_in_reg[6]),
    .I4(counter[0]),
    .I5(counter[1]),
    .O(\Mmux_counter[2]_data_in_reg[7]_Mux_4_o_3_47 )
  );
  LUT6 #(
    .INIT ( 64'hAAABAAAAAAA8AAAA ))
  Mmux__n008081 (
    .I0(data_out_0_31),
    .I1(counter[1]),
    .I2(counter[2]),
    .I3(counter[0]),
    .I4(state_FSM_FFd1_22),
    .I5(miso_IBUF_9),
    .O(_n0080[7])
  );
  LUT6 #(
    .INIT ( 64'h8A8A8A8A8A8A8ACE ))
  \state[7]_ss_Select_15_o1  (
    .I0(ss_OBUF_19),
    .I1(state_FSM_FFd1_22),
    .I2(ready_send_IBUF_10),
    .I3(counter[1]),
    .I4(counter[2]),
    .I5(counter[0]),
    .O(\state[7]_ss_Select_15_o )
  );
  IBUF   clk_IBUF (
    .I(clk),
    .O(sclk_OBUF_80)
  );
  IBUF   data_in_7_IBUF (
    .I(data_in[7]),
    .O(data_in_7_IBUF_0)
  );
  IBUF   data_in_6_IBUF (
    .I(data_in[6]),
    .O(data_in_6_IBUF_1)
  );
  IBUF   data_in_5_IBUF (
    .I(data_in[5]),
    .O(data_in_5_IBUF_2)
  );
  IBUF   data_in_4_IBUF (
    .I(data_in[4]),
    .O(data_in_4_IBUF_3)
  );
  IBUF   data_in_3_IBUF (
    .I(data_in[3]),
    .O(data_in_3_IBUF_4)
  );
  IBUF   data_in_2_IBUF (
    .I(data_in[2]),
    .O(data_in_2_IBUF_5)
  );
  IBUF   data_in_1_IBUF (
    .I(data_in[1]),
    .O(data_in_1_IBUF_6)
  );
  IBUF   data_in_0_IBUF (
    .I(data_in[0]),
    .O(data_in_0_IBUF_7)
  );
  IBUF   miso_IBUF (
    .I(miso),
    .O(miso_IBUF_9)
  );
  IBUF   ready_send_IBUF (
    .I(ready_send),
    .O(ready_send_IBUF_10)
  );
  OBUF   data_out_7_OBUF (
    .I(data_out_7_24),
    .O(data_out[7])
  );
  OBUF   data_out_6_OBUF (
    .I(data_out_6_25),
    .O(data_out[6])
  );
  OBUF   data_out_5_OBUF (
    .I(data_out_5_26),
    .O(data_out[5])
  );
  OBUF   data_out_4_OBUF (
    .I(data_out_4_27),
    .O(data_out[4])
  );
  OBUF   data_out_3_OBUF (
    .I(data_out_3_28),
    .O(data_out[3])
  );
  OBUF   data_out_2_OBUF (
    .I(data_out_2_29),
    .O(data_out[2])
  );
  OBUF   data_out_1_OBUF (
    .I(data_out_1_30),
    .O(data_out[1])
  );
  OBUF   data_out_0_OBUF (
    .I(data_out_0_31),
    .O(data_out[0])
  );
  OBUF   mosi_OBUF (
    .I(mosi_OBUF_23),
    .O(mosi)
  );
  OBUF   sclk_OBUF (
    .I(sclk_OBUF_80),
    .O(sclk)
  );
  OBUF   ss_OBUF (
    .I(ss_OBUF_19),
    .O(ss)
  );
  FD   mosi_48 (
    .C(sclk_OBUF_BUFG_8),
    .D(mosi_rstpot_70),
    .Q(mosi_OBUF_23)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_0_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[0]),
    .I2(data_in_0_IBUF_7),
    .O(data_in_reg_0_dpot_72)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_1_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[1]),
    .I2(data_in_1_IBUF_6),
    .O(data_in_reg_1_dpot_73)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_2_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[2]),
    .I2(data_in_2_IBUF_5),
    .O(data_in_reg_2_dpot_74)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_3_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[3]),
    .I2(data_in_3_IBUF_4),
    .O(data_in_reg_3_dpot_75)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_4_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[4]),
    .I2(data_in_4_IBUF_3),
    .O(data_in_reg_4_dpot_76)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_5_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[5]),
    .I2(data_in_5_IBUF_2),
    .O(data_in_reg_5_dpot_77)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_6_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[6]),
    .I2(data_in_6_IBUF_1),
    .O(data_in_reg_6_dpot_78)
  );
  LUT3 #(
    .INIT ( 8'hE4 ))
  data_in_reg_7_dpot (
    .I0(ready_send_IBUF_10),
    .I1(data_in_reg[7]),
    .I2(data_in_7_IBUF_0),
    .O(data_in_reg_7_dpot_79)
  );
  LUT6 #(
    .INIT ( 64'hAAAABAAAAAAA8AAA ))
  Mmux__n008041 (
    .I0(data_out_4_27),
    .I1(counter[0]),
    .I2(state_FSM_FFd1_22),
    .I3(counter[2]),
    .I4(counter[1]),
    .I5(miso_IBUF_9),
    .O(_n0080[3])
  );
  LUT6 #(
    .INIT ( 64'hAAAAEAAAAAAA2AAA ))
  Mmux__n008021 (
    .I0(data_out_6_25),
    .I1(state_FSM_FFd1_22),
    .I2(counter[1]),
    .I3(counter[2]),
    .I4(counter[0]),
    .I5(miso_IBUF_9),
    .O(_n0080[1])
  );
  LUT6 #(
    .INIT ( 64'hAAAABAAAAAAA8AAA ))
  Mmux__n008061 (
    .I0(data_out_2_29),
    .I1(counter[0]),
    .I2(state_FSM_FFd1_22),
    .I3(counter[1]),
    .I4(counter[2]),
    .I5(miso_IBUF_9),
    .O(_n0080[5])
  );
  LUT6 #(
    .INIT ( 64'hEAAAAAAA2AAAAAAA ))
  Mmux__n008011 (
    .I0(data_out_7_24),
    .I1(counter[1]),
    .I2(counter[2]),
    .I3(counter[0]),
    .I4(state_FSM_FFd1_22),
    .I5(miso_IBUF_9),
    .O(_n0080[0])
  );
  LUT6 #(
    .INIT ( 64'hAAAAEAAAAAAA2AAA ))
  Mmux__n008031 (
    .I0(data_out_5_26),
    .I1(state_FSM_FFd1_22),
    .I2(counter[0]),
    .I3(counter[2]),
    .I4(counter[1]),
    .I5(miso_IBUF_9),
    .O(_n0080[2])
  );
  LUT6 #(
    .INIT ( 64'hAAAABAAAAAAA8AAA ))
  Mmux__n008071 (
    .I0(data_out_1_30),
    .I1(counter[2]),
    .I2(state_FSM_FFd1_22),
    .I3(counter[0]),
    .I4(counter[1]),
    .I5(miso_IBUF_9),
    .O(_n0080[6])
  );
  LUT6 #(
    .INIT ( 64'hAAAAEAAAAAAA2AAA ))
  Mmux__n008051 (
    .I0(data_out_3_28),
    .I1(state_FSM_FFd1_22),
    .I2(counter[0]),
    .I3(counter[1]),
    .I4(counter[2]),
    .I5(miso_IBUF_9),
    .O(_n0080[4])
  );
  LUT5 #(
    .INIT ( 32'hFA3ACA0A ))
  mosi_rstpot (
    .I0(mosi_OBUF_23),
    .I1(counter[2]),
    .I2(state_FSM_FFd1_22),
    .I3(\Mmux_counter[2]_data_in_reg[7]_Mux_4_o_3_47 ),
    .I4(\Mmux_counter[2]_data_in_reg[7]_Mux_4_o_4_46 ),
    .O(mosi_rstpot_70)
  );
  LUT5 #(
    .INIT ( 32'hB7B3A6A2 ))
  \state[7]_counter[7]_select_14_OUT<1>1  (
    .I0(counter[1]),
    .I1(state_FSM_FFd1_22),
    .I2(counter[0]),
    .I3(counter[2]),
    .I4(ready_send_IBUF_10),
    .O(\state[7]_counter[7]_select_14_OUT<1> )
  );
  LUT5 #(
    .INIT ( 32'h77736662 ))
  \state[7]_counter[7]_select_14_OUT<0>1  (
    .I0(counter[0]),
    .I1(state_FSM_FFd1_22),
    .I2(counter[1]),
    .I3(counter[2]),
    .I4(ready_send_IBUF_10),
    .O(\state[7]_counter[7]_select_14_OUT<0> )
  );
  LUT5 #(
    .INIT ( 32'hAF8FAA8A ))
  \state[7]_counter[7]_select_14_OUT<2>1  (
    .I0(counter[2]),
    .I1(counter[0]),
    .I2(state_FSM_FFd1_22),
    .I3(counter[1]),
    .I4(ready_send_IBUF_10),
    .O(\state[7]_counter[7]_select_14_OUT<2> )
  );
  LUT5 #(
    .INIT ( 32'hFFFDAAA8 ))
  \state_FSM_FFd1-In1  (
    .I0(state_FSM_FFd1_22),
    .I1(counter[1]),
    .I2(counter[2]),
    .I3(counter[0]),
    .I4(ready_send_IBUF_10),
    .O(\state_FSM_FFd1-In )
  );
  BUFG   sclk_OBUF_BUFG (
    .O(sclk_OBUF_BUFG_8),
    .I(sclk_OBUF_80)
  );
  INV   \state[7]_counter[7]_select_14_OUT<1>31_cepot_INV_0  (
    .I(state_FSM_FFd1_22),
    .O(\state[7]_counter[7]_select_14_OUT<1>31_cepot )
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif

