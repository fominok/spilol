#include "systemc.h"
#include "pmod_oled_tb.h"
#include "pmod_oled.h"

SC_MODULE(SYSTEM) {
  pmod_oled_spi_connector_tb *tb0;
  pmod_oled_spi_connector *con0;

  sc_signal<bool> rst, data_set, sclk, ss, mosi, ready, miso;
  sc_signal<sc_uint<8> > data_in;

  sc_clock clk;

  sc_trace_file *wf = sc_create_vcd_trace_file("pmod_oled");

  SC_CTOR(SYSTEM) : clk("clk", 10, SC_NS) {
    tb0 = new pmod_oled_spi_connector_tb("tb0");
    tb0->clk(clk);
    tb0->sclk(sclk);
    tb0->rst(rst);
    tb0->data_set(data_set);
    tb0->data_in(data_in);
    tb0->ss(ss);
    tb0->mosi(mosi);
    tb0->miso(miso);
    tb0->ready(ready);

    con0 = new pmod_oled_spi_connector("con0");
    con0->clk(clk);
    con0->sclk(sclk);
    con0->rst(rst);
    con0->data_set(data_set);
    con0->data_in(data_in);
    con0->ss(ss);
    con0->mosi(mosi);
    con0->miso(miso);
    con0->ready(ready);

    sc_trace(wf, clk, "clk");
    sc_trace(wf, sclk, "sclk");
    sc_trace(wf, rst, "rst");
    sc_trace(wf, data_set, "data_set");
    sc_trace(wf, data_in, "data_in");
    sc_trace(wf, ss, "ss");
    sc_trace(wf, mosi, "mosi");
    sc_trace(wf, ready, "ready");
  }

  ~SYSTEM() {
    delete tb0;
    delete con0;

    sc_close_vcd_trace_file(wf);
  }
};

SYSTEM *top = NULL;

int sc_main(int argc, char* argv[]) {
  top = new SYSTEM("top");
  sc_start();
  return 0;
}
