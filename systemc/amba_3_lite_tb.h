#include "systemc.h"

SC_MODULE(amba_3_lite_tb) {
  sc_in_clk clk;
  // `_in` means into bus
  // `_out` means from bus

  sc_in<bool> hwrite_tb_out;
  sc_in<sc_uint<32> > hwdata_tb_out;
  sc_in<sc_uint<32> > haddr_tb_out;
  sc_in<sc_uint<32> > hrdata_tb;
  sc_in<bool> hsel_1_tb;
  sc_in<bool> hsel_2_tb;
  sc_in<bool> hsel_3_tb;

  sc_out<bool> hwrite_tb_in;
  sc_out<sc_uint<32> > hwdata_tb_in;
  sc_out<sc_uint<32> > haddr_tb_in;
  sc_out<sc_uint<32> > hrdata_1_tb;
  sc_out<sc_uint<32> > hrdata_2_tb;
  sc_out<sc_uint<32> > hrdata_3_tb;

  void test() {
    wait(2);
    hwrite_tb_in.write(1);
    hwdata_tb_in.write(0x1337);
    haddr_tb_in.write(0x00020000);
    wait();
    hwrite_tb_in.write(0);
    wait();
    //multiplexing test
    hrdata_1_tb.write(0x420);
    hrdata_2_tb.write(0x322);
    hrdata_3_tb.write(0x228);
    wait(); // hrdata to master must be 322
    haddr_tb_in.write(0);
    wait(2);
    sc_stop();
  }

  SC_CTOR(amba_3_lite_tb) {
    SC_CTHREAD(test, clk.pos());
  }
};
