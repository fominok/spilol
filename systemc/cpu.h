#pragma once
#include "systemc.h"

SC_MODULE(cpu)
{
sc_in <bool> clk;
sc_in <sc_uint<32> > hrdata;
sc_out<sc_uint<32> > hwdata;
sc_out<sc_uint<32> > haddr;
sc_out<bool> hwrite;

void app();
void pub_wait();

SC_CTOR(cpu) {
        SC_THREAD(app);
        sensitive << clk.pos();
}

};

