#pragma once
#include "systemc.h"

SC_MODULE(pmod_oled_receiver) {
  sc_in<bool> sclk;
  sc_in<bool> mosi;
  sc_in<bool> ss;

  sc_out<bool> miso;

  // Locals
  sc_uint<8> buffer;
  int i;
  void receive() {
    buffer = 0;
    i = 0;
    miso.write(0);
    wait();

    while(true){
      if (!ss.read()) {
        buffer[7 - i++] = mosi.read();
        if (i == 8) {
          cout << "Buffer: " << buffer.to_string(SC_HEX) << endl;
          i = 0;
        }
      }
      wait();
    }
  }

  SC_CTOR(pmod_oled_receiver) {
    SC_CTHREAD(receive, sclk.pos());
  }
};
