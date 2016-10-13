/*****************************************************************************
 
  main.cpp -- This is the top level file instantiating the modules and
              binding ports to signals.
 
 *****************************************************************************/

#include "systemc.h"
#include "spi.h"
#include "test_spi.h"

int sc_main(int ac, char *av[])
{
    sc_signal<sc_int<8> > data_in, data_out;
    sc_signal<bool> miso, sclk, ss, mosi, rst, enable;

    data_in.write(0xBE);
    sc_clock clk ("ID", 10, SC_NS, 0.5, 10, SC_NS, true);

    spi_master spi ("SPI_master");
    spi.data_in(data_in);
    spi.data_out(data_out);
    spi.clk(clk);
    spi.rst(rst);
    spi.enable(enable);
    spi.miso(miso);
    spi.sclk(sclk);
    spi.ss(ss);
    spi.mosi(mosi);

    test_slave test ("SPI_slave");
    test.clk(sclk);
    test.mosi(mosi);
    test.miso(miso);
    test.ss(ss);
    test.rst(rst);
    test.enable(enable);
    test.data_in(data_in);

    sc_trace_file *tf;
    tf = sc_create_vcd_trace_file("waves");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, rst, "rst");
    sc_trace(tf, sclk, "sclk");
    sc_trace(tf, ss, "SS");
    sc_trace(tf, mosi, "MOSI");
    sc_trace(tf, miso, "MISO");
    sc_trace(tf, enable, "enable");
    sc_trace(tf, data_in, "data_in");
    sc_trace(tf, data_out, "data_out");

    sc_start();

    return 0;
}

