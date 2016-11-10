#include "systemc.h"
#include "pmod_oled_tb.h"
#include "pmod_oled.h"
#include "pmod_oled_receiver.h"

SC_MODULE(SYSTEM) {
  pmod_oled_ctrl_tb *tb0;
  pmod_oled_ctrl *ctrl0;
  pmod_oled_receiver *recv0;

  sc_signal<bool> rst, sclk, ss, mosi, miso, hwrite, hsel;
  sc_signal<sc_uint<32> > hwdata, haddr, hrdata;

  sc_clock clk;

  sc_trace_file *wf = sc_create_vcd_trace_file("pmod_oled");

  SC_CTOR(SYSTEM) : clk("clk", 10, SC_NS) {
    tb0 = new pmod_oled_ctrl_tb("tb0");
    tb0->clk(clk);
    tb0->rst(rst);
    tb0->hwrite(hwrite);
    tb0->hrdata(hrdata);
    tb0->hwdata(hwdata);
    tb0->haddr(haddr);
    tb0->sclk(sclk);
    tb0->ss(ss);
    tb0->mosi(mosi);
    tb0->miso(miso);
    tb0->hsel(hsel);

    ctrl0 = new pmod_oled_ctrl("ctrl0");
    ctrl0->clk(clk);
    ctrl0->rst(rst);
    ctrl0->hwrite(hwrite);
    ctrl0->hrdata(hrdata);
    ctrl0->hwdata(hwdata);
    ctrl0->haddr(haddr);
    ctrl0->sclk(sclk);
    ctrl0->ss(ss);
    ctrl0->mosi(mosi);
    ctrl0->miso(miso);
    ctrl0->hsel(hsel);

    recv0 = new pmod_oled_receiver("recv0");
    recv0->sclk(sclk);
    recv0->ss(ss);
    recv0->mosi(mosi);
    recv0->miso(miso);


    sc_trace(wf, clk, "clk");
    sc_trace(wf, rst, "rst");
    sc_trace(wf, hwrite, "hwrite");
    sc_trace(wf, hrdata, "hrdata");
    sc_trace(wf, hwdata, "hwdata");
    sc_trace(wf, haddr, "haddr");
    sc_trace(wf, sclk, "sclk");
    sc_trace(wf, ss, "ss");
    sc_trace(wf, mosi, "mosi");
    sc_trace(wf, miso, "miso");
    sc_trace(wf, hsel, "hsel");
  }

  ~SYSTEM() {
    delete tb0;
    delete ctrl0;
    delete recv0;

    sc_close_vcd_trace_file(wf);
  }
};

SYSTEM *top = NULL;

int sc_main(int argc, char* argv[]) {
  top = new SYSTEM("top");
  sc_start();
  return 0;
}
