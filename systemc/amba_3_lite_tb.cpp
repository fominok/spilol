#include "systemc.h"
#include "amba_3_lite.h"
#include "amba_3_lite_tb.h"

SC_MODULE(SYSTEM) {
  amba_3_lite_tb *amba_tb0;
  amba_3_lite *amba0;

  sc_signal<bool> hwrite_in, hwrite_out, hsel_1, hsel_2, hsel_3;
  sc_signal<sc_uint<32> > hwdata_in, hwdata_out, haddr_in, haddr_out,
    hrdata, hrdata_1, hrdata_2, hrdata_3;

  sc_clock clk_sig;

  sc_trace_file *wf = sc_create_vcd_trace_file("amba");

  SC_CTOR(SYSTEM) : clk_sig("clk_sig", 10, SC_NS) {
    amba_tb0 = new amba_3_lite_tb("amba_tb0");

    amba_tb0->clk(clk_sig);
    amba_tb0->hwrite_tb_out(hwrite_out);
    amba_tb0->hwdata_tb_out(hwdata_out);
    amba_tb0->haddr_tb_out(haddr_out);
    amba_tb0->hrdata_tb(hrdata);
    amba_tb0->hsel_1_tb(hsel_1);
    amba_tb0->hsel_2_tb(hsel_2);
    amba_tb0->hsel_3_tb(hsel_3);

    amba_tb0->hwrite_tb_in(hwrite_in);
    amba_tb0->hwdata_tb_in(hwdata_in);
    amba_tb0->haddr_tb_in(haddr_in);
    amba_tb0->hrdata_1_tb(hrdata_1);
    amba_tb0->hrdata_2_tb(hrdata_2);
    amba_tb0->hrdata_3_tb(hrdata_3);

    amba0 = new amba_3_lite("amba0");

    amba0->hwrite_s(hwrite_out);
    amba0->hwdata_s(hwdata_out);
    amba0->haddr_s(haddr_out);
    amba0->hrdata(hrdata);
    amba0->hsel_1(hsel_1);
    amba0->hsel_2(hsel_2);
    amba0->hsel_3(hsel_3);

    amba0->hwrite_m(hwrite_in);
    amba0->hwdata_m(hwdata_in);
    amba0->haddr_m(haddr_in);
    amba0->hrdata_1(hrdata_1);
    amba0->hrdata_2(hrdata_2);
    amba0->hrdata_3(hrdata_3);

    sc_trace(wf, clk_sig, "CLK");
    sc_trace(wf, hwrite_out, "hwrite_out");
    sc_trace(wf, hwdata_out, "hwdata_out");
    sc_trace(wf, haddr_out, "haddr_out");
    sc_trace(wf, hrdata, "hrdata");
    sc_trace(wf, hsel_1, "hsel_1");
    sc_trace(wf, hsel_2, "hsel_2");
    sc_trace(wf, hsel_3, "hsel_3");
    sc_trace(wf, hwrite_in, "hwrite_in");
    sc_trace(wf, hwdata_in, "hwdata_in");
    sc_trace(wf, haddr_in, "haddr_in");
    sc_trace(wf, hrdata_1, "hrdata_1");
    sc_trace(wf, hrdata_2, "hrdata_2");
    sc_trace(wf, hrdata_3, "hrdata_3");
  }

  ~SYSTEM() {
    delete amba_tb0;
    delete amba0;

    sc_close_vcd_trace_file(wf);
  }
};

SYSTEM *top = NULL;

int sc_main(int argc, char* argv[]) {
  top = new SYSTEM("top");
  sc_start();
  return 0;
}
