#include "systemc.h"

SC_MODULE (amba_3_lite) {
  //Master side
  sc_in<bool> hwrite_m;
  sc_in<sc_uint<32> > hwdata_m;
  sc_in<sc_uint<32> > haddr_m;

  sc_out<sc_uint<32> > hrdata;

  //Slaves side
  //sc_in<sc_uint<32> > hrdata_1;
  sc_in<sc_uint<32> > hrdata_2;
  //sc_in<sc_uint<32> > hrdata_3;

  sc_out<bool> hwrite_s;
  sc_out<sc_uint<32> > hwdata_s;
  sc_out<sc_uint<32> > haddr_s;
  //sc_out<bool> hsel_1;
  sc_out<bool> hsel_2;
  //sc_out<bool> hsel_3;

  void multiplexing() {
    sc_uint<2> hsel_i = (haddr_m.read() & (3 << 16)) >> 16;

    //hsel_1.write(0);
    hsel_2.write(0);
    //hsel_3.write(0);

    //Transparent signals
    hwdata_s.write(hwdata_m);
    haddr_s.write(haddr_m);
    hwrite_s.write(hwrite_m);

    if (!hsel_i) {
      hrdata.write(0);
      return;
    }

    //Choosing hsel_x and input data
    switch(hsel_i) {
      // case 1:
      //   hsel_1.write(1);
      //   hrdata.write(hrdata_1);
      //   break;
    case 2:
      hsel_2.write(1);
      hrdata.write(hrdata_2);
      break;
      //case 3:
      //  hsel_3.write(1);
      //  hrdata.write(hrdata_3);
      //  break;
    }
  }

  SC_CTOR (amba_3_lite) {
    SC_METHOD(multiplexing);
    sensitive << haddr_m
      //           << hrdata_1
              << hrdata_2
      //        << hrdata_3
              << hwrite_m
              << hwdata_m;
  }
};
