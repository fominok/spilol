#pragma once
#include "systemc.h"

//SC_MODULE(pmod_oled_bus_converter) {
//
//};

SC_MODULE(pmod_oled_spi_connector) {
  //Global
  sc_in_clk clk;
  sc_in<bool> rst;

  //Bus converter side
  sc_in<sc_uint<8> > data_in;
  sc_in<bool> data_set;

  sc_out<bool> ready; // Byte sent and ready for a new one

  ////Screen side
  sc_in<bool> miso;

  sc_out<bool> sclk;
  sc_out<bool> mosi;
  sc_out<bool> ss;

  //Locals
  sc_uint<8> in_buffer;
  bool transfer_on;
  bool qclk_tmp;
  bool qclk;
  int i;

  void transmit() {
    sclk.write(1);
    mosi.write(0);
    ready.write(1);
    ss.write(1);
    transfer_on = false;
    qclk = 0;
    qclk_tmp = 0;
    in_buffer = 0;
    i = 7;

    wait();

    while(true) {
      if (data_set.read() && !transfer_on) {
        in_buffer = data_in.read();
        transfer_on = true;
        ready.write(0);
        ss.write(0);
        mosi.write(0);
      }
      if (transfer_on) {
        qclk_tmp = !qclk_tmp;
        if (qclk_tmp) {
          qclk = !qclk;
          if (!qclk) {
            if (i < 0) {
              sclk.write(1);
              mosi.write(0);
              ready.write(1);
              ss.write(1);
              transfer_on = false;
              qclk = 0;
              qclk_tmp = 0;
              in_buffer = 0;
              i = 7;
              qclk = 1;
            }
            mosi.write(in_buffer[i--]);
          }
        }
        sclk.write(qclk);
      }
      wait();
    }
  }

  SC_CTOR(pmod_oled_spi_connector) {
    SC_CTHREAD(transmit, clk.pos());
    reset_signal_is(rst, true);
  }

};

//SC_MODULE(pmod_oled_ctrl) {
//  //--Begin interface
//  //Global
//  sc_in_clk clk;
//  sc_in<bool> rst;
//
//  //AMBA side
//  sc_in<bool> hwrite;
//  sc_in<sc_uint<32> > hwdata;
//  sc_in<sc_uint<32> > haddr;
//  sc_in<bool> hsel;
//
//  sc_out<sc_uint<32> > hrdata;
//
//  //SPI side
//  sc_in<bool> miso;
//
//  sc_out<bool> sclk;
//  sc_out<bool> mosi;
//  sc_out<bool> ss;
//  //--End interface
//
//
//  SC_CTOR(pmod_oled_ctrl) {
//
//  }
//};
