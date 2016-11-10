#pragma once
#include "systemc.h"

SC_MODULE(pmod_oled_bus_converter) {
  sc_in_clk clk;
  sc_in<bool> rst;

  //AMBA side
  sc_in<bool> hwrite_s;
  sc_in<sc_uint<32> > hwdata_s;
  sc_in<sc_uint<32> > haddr_s;
  sc_in<bool> hsel;

  sc_out<sc_uint<32> > hrdata;

  //SPI connector sidey
  sc_in<bool> ready; // Byte sent and ready for a new one

  sc_out<sc_uint<8> > data_in;
  sc_out<bool> data_set;

  //Locals
  bool transfer_on;
  sc_uint<32> buffer;
  int bts; // bytes to send
  bool actually_started;
  bool byte_sent;

  void transmit() {
    data_set.write(0);
    data_in.write(0);
    transfer_on = false;
    hrdata.write(0);
    buffer = 0;
    bts = 0;
    actually_started = false;
    byte_sent = false;

    wait();

    while(true) {
      // Start transfer
      if (hsel.read() && hwrite_s.read() && !transfer_on) {

        // Decoding
        sc_uint<16> reg_addr = haddr_s.read() & 0xFFFF;
        actually_started = false;

        switch(reg_addr) {
        case 0x2000:
          buffer = 0xAE | hwdata_s.read()[0];
          bts = 1;
          transfer_on = true;
          break;
        }
      }
      // Deny transfer
      //else if (hsel.read() && hwrite_s.read() && transfer_on) {
      //  // Maybe CPU should ask me first
      //  //            |
      //  //            V
      //}
      // Ask controller's business
      //else if (hsel.read() && !hwrite_s.read()) {
      //  if (transfer_on) {
      //    // Zakhlebnulsya govnom
      //    hrdata.write(1);
      //  } else {
      //    hrdata.write(0);
      //  }
      //}

      // Start one byte spi tranfer
      hrdata.write(transfer_on);
      if (transfer_on) {
        if (ready.read() && bts && !byte_sent) {
          data_in.write(buffer.range(7,0));
          data_set.write(1);
          buffer = buffer >> 8;
          bts--;
          byte_sent = true;
          actually_started = false;
        }
        // Spi connector busy
        else if (!ready.read() && bts) {
          actually_started = true;
          byte_sent = false;
          data_in.write(0);
          data_set.write(0);
        }
        else if (!ready.read() && !bts) {
          actually_started = true;
          byte_sent = false;
          data_in.write(0);
          data_set.write(0);
        }
        // Finished transfer
        else if (ready.read() && !bts) {
          if (actually_started) {
            transfer_on = false;
            data_in.write(0);
            data_set.write(0);
            hrdata.write(0);
            actually_started = false;
          }
        }
      }
      wait();
    }
  }

  SC_CTOR(pmod_oled_bus_converter) {
    SC_CTHREAD(transmit, clk.pos());
    reset_signal_is(rst, true);
  }

};

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
      if (data_set.read() && !transfer_on && ready) {
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
              sclk.write(1);
              continue;
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

SC_MODULE(pmod_oled_ctrl) {
  //--Begin interface
  //Global
  sc_in_clk clk;
  sc_in<bool> rst;

  //AMBA side
  sc_in<bool> hwrite;
  sc_in<sc_uint<32> > hwdata;
  sc_in<sc_uint<32> > haddr;
  sc_in<bool> hsel;

  sc_out<sc_uint<32> > hrdata;

  //SPI side
  sc_in<bool> miso;

  sc_out<bool> sclk;
  sc_out<bool> mosi;
  sc_out<bool> ss;
  //--End interface

  //Connections
  sc_signal<sc_uint<8> > data_in_sig;
  sc_signal<bool> ready_sig, data_set_sig;

  //Modules
  pmod_oled_bus_converter bus_conv;
  pmod_oled_spi_connector spi_conn;

 SC_CTOR(pmod_oled_ctrl) : bus_conv("BUS_CONV"), spi_conn("SPI_CONN") {
    bus_conv.clk(clk);
    bus_conv.rst(rst);
    bus_conv.hwrite_s(hwrite);
    bus_conv.haddr_s(haddr);
    bus_conv.hwdata_s(hwdata);
    bus_conv.hsel(hsel);
    bus_conv.hrdata(hrdata);

    bus_conv.data_in(data_in_sig);
    bus_conv.ready(ready_sig);
    bus_conv.data_set(data_set_sig);
    spi_conn.data_in(data_in_sig);
    spi_conn.ready(ready_sig);
    spi_conn.data_set(data_set_sig);

    spi_conn.clk(clk);
    spi_conn.rst(rst);
    spi_conn.miso(miso);
    spi_conn.mosi(mosi);
    spi_conn.sclk(sclk);
    spi_conn.ss(ss);
  }
};
