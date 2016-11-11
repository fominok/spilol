#include "systemc.h"
#include "cpu.h"
#include "pmod_oled.h"
#include "pmod_oled_receiver.h"
#include "amba_3_lite.h"
#include "EVM.h"
#include "din_dout.h"

SC_MODULE(SYSTEM) {

  cpu *cpu0;
  pmod_oled_ctrl *ctrl0;
  pmod_oled_receiver *recv0;
  amba_3_lite *amba0;
  DinDout *dido0;
  EVM *evm;

  sc_clock clk;
  sc_signal<bool> rst;
  //cpu
  sc_signal<sc_uint<32> > hrdata_cpu, hwdata_cpu, haddr_cpu;
  sc_signal<bool> hwrite_cpu;
  //generic
  sc_signal<sc_uint<32> > hwdata, haddr;
  sc_signal<bool> hwrite;
  //ctrl
  sc_signal<sc_uint<32> > hrdata_ctrl;
  sc_signal<bool> hsel_ctrl;
  //pmod oled
  sc_signal<bool> sclk, ss, miso, mosi;
  //discrete
  sc_signal<sc_uint<32> > hrdata_disc;
  sc_signal<bool> hsel_disc;

  sc_trace_file *wf = sc_create_vcd_trace_file("EVM");

  SC_CTOR(SYSTEM) : clk("clk", 10, SC_NS) {
    evm = new EVM("EVM");
    evm->clk(clk);
    evm->rst(rst);

    cpu0 = new cpu("cpu0");
    cpu0->clk(clk);
    cpu0->hrdata(hrdata_cpu);
    cpu0->hwdata(hwdata_cpu);
    cpu0->haddr(haddr_cpu);
    cpu0->hwrite(hwrite_cpu);
    cpu0->rst(rst);

    amba0 = new amba_3_lite("amba0");
    amba0->hrdata(hrdata_cpu);
    amba0->hwdata_m(hwdata_cpu);
    amba0->haddr_m(haddr_cpu);
    amba0->hwrite_m(hwrite_cpu);

    amba0->hrdata_2(hrdata_ctrl);
    amba0->hwdata_s(hwdata);
    amba0->haddr_s(haddr);
    amba0->hwrite_s(hwrite);
    amba0->hsel_2(hsel_ctrl);

    amba0->hrdata_1(hrdata_disc);
    amba0->hsel_1(hsel_disc);

    ctrl0 = new pmod_oled_ctrl("ctrl0");
    ctrl0->clk(clk);
    ctrl0->rst(rst);
    ctrl0->hrdata(hrdata_ctrl);
    ctrl0->hwdata(hwdata);
    ctrl0->haddr(haddr);
    ctrl0->hwrite(hwrite);
    ctrl0->hsel(hsel_ctrl);

    ctrl0->sclk(sclk);
    ctrl0->mosi(mosi);
    ctrl0->miso(miso);
    ctrl0->ss(ss);

    dido0 = new DinDout("dido0");
    dido0->hclk_i(clk);
    dido0->hresetn_i(rst);
    dido0->haddr_bi(haddr);
    dido0->hwdata_bi(hwdata);
    dido0->hrdata_bo(hrdata_disc);
    dido0->hwrite_i(hwrite);
    dido0->hsel_i(hsel_disc);

    recv0 = new pmod_oled_receiver("recv0");
    recv0->sclk(sclk);
    recv0->mosi(mosi);
    recv0->miso(miso);
    recv0->ss(ss);

    sc_trace(wf, clk, "clk");
  }
  ~SYSTEM() {
    delete cpu0;
    delete ctrl0;
    delete recv0;
    delete amba0;
    delete dido0;
    delete evm;

    sc_close_vcd_trace_file(wf);
  }
};

SYSTEM *top = NULL;

int sc_main(int argc, char* argv[]) {
  top = new SYSTEM("top");
  sc_start();
  return 0;
}
