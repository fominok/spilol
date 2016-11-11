#pragma one
#include "systemc.h"

SC_MODULE(EVM) {
  sc_in_clk clk;
  sc_out<bool> rst;

  //sc_in<bool> sclk;
  //sc_in<bool> mosi;
  //sc_in<bool> miso;
  //sc_in<bool> ss;

  void source() {
    rst.write(1);
    wait(5);
    rst.write(0);
    wait(700);
    sc_stop();
  }

  SC_CTOR(EVM) {
    SC_CTHREAD(source, clk.pos());
  }
};
