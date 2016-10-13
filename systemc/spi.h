#include "systemc.h"

SC_MODULE(quarted_clk)
{
sc_in<bool> clk;
sc_out<bool> qclk;

sc_signal<bool> sc_tmp;

void quarter() {
    if (sc_tmp) {
        qclk = ~qclk;
    }
    sc_tmp = ~sc_tmp;
}

SC_CTOR(quarted_clk) {
    SC_METHOD(quarter);
    sensitive_pos << clk;
}

};

