#pragma once
#include "systemc.h"

SC_MODULE (pmod_oled_spi_connector_tb) {
  sc_in_clk clk;
  sc_out<bool> rst;
  sc_out<bool> data_set;
  sc_out<sc_uint<8> > data_in;
  sc_out<bool> miso;

  sc_in<bool> sclk;
  sc_in<bool> ss;
  sc_in<bool> mosi;
  sc_in<bool> ready;

  void source() {
    rst.write(1);
    wait(2);
    rst.write(0);
    wait(2);

    data_in.write(0x37);
    data_set.write(1);
    wait();
    data_set.write(0);
    wait();
    while(!ready.read()) {
      wait();
    }
    data_in.write(0x42);
    data_set.write(1);
    wait();
    data_set.write(0);
    wait(50);
    sc_stop();
  }

  SC_CTOR(pmod_oled_spi_connector_tb) {
    SC_CTHREAD(source, clk.pos());
  }
};
