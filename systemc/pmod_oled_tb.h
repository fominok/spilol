#pragma once
#include "systemc.h"

SC_MODULE (pmod_oled_ctrl_tb) {
  //Global
  sc_in_clk clk;
  sc_out<bool> rst;

  //TB Bus side
  sc_in<sc_uint<32> > hrdata;

  sc_out<bool> hwrite;
  sc_out<sc_uint<32> > hwdata;
  sc_out<sc_uint<32> > haddr;
  sc_out<bool> hsel;


  //TB PmodOled side
  sc_in<bool> sclk;
  sc_in<bool> mosi;
  sc_in<bool> ss;

  sc_in<bool> miso;

  void source() {
    rst.write(1);
    wait(2);
    rst.write(0);
    wait(1);
    hwdata.write(1);
    haddr.write(0x00012000);
    hsel.write(1);
    hwrite.write(1);
    wait(5);
    //hwdata.write(0);
    //haddr.write(0);
    hsel.write(0);
    hwrite.write(0);
    wait(100);
    sc_stop();
  }

  SC_CTOR(pmod_oled_ctrl_tb) {
    SC_CTHREAD(source, clk.pos());
  }
};
