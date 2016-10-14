#pragma once
#include "systemc.h"

/* A module to halve the frequency of a clock. */
SC_MODULE(halved_clk)
{
sc_in<bool> clk;
sc_out<bool> hclk;

void invert() {
    hclk = !hclk;
}

SC_CTOR(halved_clk) {
    SC_METHOD(invert);
    sensitive << clk.pos();
}

};

/* A module to reduce the frequency of a clock to a quarter of the original. */
SC_MODULE(quarted_clk)
{
sc_in<bool> clk;
sc_out<bool> qclk;

halved_clk c1, c2; 
sc_signal<bool> tmp;

SC_CTOR(quarted_clk): c1("C1"), c2("C2") {
    c1.clk(clk);
    c1.hclk(tmp);

    c2.clk(tmp);
    c2.hclk(qclk);
}

};

/* A module for clock that only optionally ticks. */
SC_MODULE(opt_clk)
{
sc_in<bool> clk, n_en;
sc_out<bool> oclk;

void tick() {
    oclk.write(clk.read() && !n_en.read());
}

SC_CTOR(opt_clk) {
    SC_METHOD(tick);
    sensitive << clk;
}
};

