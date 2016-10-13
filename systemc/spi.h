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

/* The part of SPI mode 3 that's responsible for receiving. */
SC_MODULE(spi_rx)
{
sc_out<sc_uint<8> > data_out;
sc_in<sc_uint<3> > ctr;
sc_in<bool> clk, in, rst;

void rx() {
    if (rst) {
        data_out.write(0);
    } else {
        sc_uint<8> data_out_tmp = data_out.read();
        data_out_tmp[ctr.read()] = in.read();
        data_out.write(data_out_tmp);
    }
}

SC_CTOR(spi_rx) {
    SC_METHOD(rx);
    sensitive << clk.pos();
}
};

/* The part of SPI mode 3 that's responsible for transmission. */
SC_MODULE(spi_tx)
{
sc_in<sc_uint<8> > data_in;
sc_in<sc_uint<3> > ctr;
sc_in<bool> clk;
sc_out<bool> out;

void tx() {
    out = data_in.read()[ctr.read()];
}

SC_CTOR(spi_tx) {
    SC_METHOD(tx);
    sensitive << clk.pos();
}
};

/* Main loop thread for SPI master with mode 3. */
SC_MODULE(spi_master_loop)
{
sc_in<bool> clk, rst, enable;
sc_in<sc_uint<8> > input;
sc_out<bool> ss, do_tx, do_rx;
sc_out<sc_uint<3> > ctr;
sc_out<sc_uint<8> > cache;

void state() {
    bool enabled = false;
    bool trailing = false;
    int ctr_temp = 0;
    ss.write(true);

    while (true) {
        wait();
        do_tx = false;
        do_rx = false;
        if (clk) {
            if (rst) {
                ss.write(true);
                cache = 0;
                enabled = false;
                trailing = false;
                ctr_temp = 0;
            } else {
                if (trailing) {
                    trailing = false;
                    ss.write(true);
                } else if (enabled && (ctr_temp == 7)) {
                    do_tx = true;
                    trailing = true;
                } else if (enable && !enabled) {
                    ss.write(false);
                    ctr_temp = -1;
                    cache = input;
                    enabled = true;
                } else if (enabled) {
                    do_tx = true;
                    ++ctr_temp;
                }
                ctr.write(ctr_temp);
            }
        } else {
            if (enabled) {
                do_rx = true;
            }
        }
    }
}

SC_CTOR(spi_master_loop) {
    SC_THREAD(state);
    sensitive << clk;
}
};

/* SPI master with mode 3. */
SC_MODULE(spi_master)
{
sc_out<sc_uint<8> > data_in;
sc_out<sc_uint<8> > data_out;
sc_in<bool> clk, rst, enable, miso;
sc_out<bool> sclk, ss, mosi;

spi_rx rx;
spi_tx tx;
quarted_clk qclk;
spi_master_loop lp;

sc_signal<sc_uint<3> > ctr;
sc_signal<sc_uint<8> > cache;
sc_signal<bool> do_tx, do_rx;

SC_CTOR(spi_master):
    rx("RX"), tx("TX"), qclk("QCLK"), lp("LP"),
    do_tx("do_tx"), do_rx("do_rx") {
        qclk.clk(clk);
        qclk.qclk(sclk);

        lp.clk(sclk);
        lp.rst(rst);
        lp.enable(enable);
        lp.input(data_in);
        lp.ss(ss);
        lp.do_tx(do_tx);
        lp.do_rx(do_rx);
        lp.ctr(ctr);
        lp.cache(cache);

        rx.data_out(data_out);
        rx.ctr(ctr);
        rx.clk(do_rx);
        rx.in(miso);
        rx.rst(rst);

        tx.data_in(cache);
        tx.ctr(ctr);
        tx.clk(do_tx);
        tx.out(mosi);
    }
};

