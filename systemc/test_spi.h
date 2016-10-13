#include "systemc.h"

SC_MODULE(test_slave) {
sc_out<bool> miso, rst, enable;
sc_in<bool> mosi, clk, ss;
sc_out<sc_uint<8> > data_in;

void send() {

    wait();
    rst.write(true);
    wait();
    rst.write(false);
    data_in.write(0x37);
    enable.write(true);
    wait();
    while (ss.read() != true) {
        wait();
    }
    wait();
    miso.write(1);
    wait();
    miso.write(1);
    wait();
    miso.write(0);
    wait();
    miso.write(0);
    wait();
    miso.write(1);
    wait();
    miso.write(0);
    wait();
    miso.write(0);
    wait();
    miso.write(0);
    wait();
    for (int i = 0; i < 10; ++i) {
        wait();
    }
    sc_stop();
}

SC_CTOR(test_slave) {
    SC_THREAD(send);
    sensitive << clk.pos();
}

};

