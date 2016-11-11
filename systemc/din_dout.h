#ifndef __DIN_DOUT_H
#define __DIN_DOUT_H

#include <systemc.h>
#include <stdio.h>

// Register map of bus slave
#define DIN_DOUT_IN_REG   0x00000000
#define DIN_DOUT_OUT_REG  0x00000004


SC_MODULE(DinDout)
{
  sc_in<bool> hclk_i;
  sc_in<bool> hresetn_i;
  sc_in<sc_uint<32> >  haddr_bi;
  sc_in<sc_uint<32> >  hwdata_bi;
  sc_out<sc_uint<32> > hrdata_bo;
  sc_in<bool> hwrite_i;
  sc_in<bool> hsel_i;

  sc_uint<16> switches, leds;

  SC_CTOR(DinDout)
  {
    SC_METHOD(bus_slave);
    sensitive << hclk_i.pos() << hresetn_i.pos();

    SC_THREAD(user_input); // imitation of switches moving by user
    sensitive << hclk_i.pos();

    leds = 0;
  }

  void set_base_address(sc_uint<32> base_addr)
  {
    this->base_addr = base_addr;
  }

 private:
  sc_uint<32> base_addr;

  void bus_slave() {
    static bool wr_flag = false;
    static sc_uint<32> wr_addr = 0;

    if (!hresetn_i.read())
      {
        wr_flag = false;
        wr_addr = 0;

        leds = 0;
      }
    else if (hclk_i.read() && hsel_i.read())
      {
        if (wr_flag)
          {
            execute_write((sc_uint<16>) (wr_addr - base_addr), hwdata_bi.read());
            wr_flag = false;
          }
        if (hwrite_i.read())
          {
            wr_flag = true;
            wr_addr = haddr_bi.read();
          }
        else
          {
            hrdata_bo.write((sc_uint<16>) (execute_read(haddr_bi.read() - base_addr)));
          }
      }
  }
  void user_input() {
    switches = 0x7895;
    printf("Switches new state: 0x%04X\n", (unsigned short) switches);
    wait(100, SC_NS);
    switches = 0x55AA;
    printf("Switches new state: 0x%04X\n", (unsigned short) switches);
    wait(100, SC_NS);
    switches = 0x7744;
    printf("Switches new state: 0x%04X\n", (unsigned short) switches);
  }

  sc_uint<32> execute_read(sc_uint<16> addr) {

    sc_uint<32> data;

    switch (addr)
      {
      case DIN_DOUT_IN_REG:
        data = switches;
        break;
      case DIN_DOUT_OUT_REG:
        data = leds;
        break;
      default:
        data = 0;
        break;
      }
    return data;
  }
  void execute_write(sc_uint<16> addr, sc_uint<32> data) {
    switch (addr)
      {
      case DIN_DOUT_OUT_REG:
        leds = data;
        break;
      default:
        break;
      }
  }
};

#endif // __DIN_DOUT_H
