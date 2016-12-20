#ifndef amba_spi_h_INCLUDED
#define amba_spi_h_INCLUDED

#include "systemc.h"
#include "spi.h"

SC_MODULE(amba_spi)
{
    sc_in <bool>         hclk_i;
    sc_in <bool>         hresetn_i;
    sc_in <sc_uint<32> > haddr_bi;
    sc_in <sc_uint<32> > hwdata_bi;
    sc_out<sc_uint<32> > hrdata_bo;
    sc_in <bool>         hwrite_i;
    sc_in <bool>         hsel_i;

    sc_out<bool>         spi_sclk;
    sc_out<bool>         spi_ss;
    sc_out<bool>         spi_mosi;
    sc_in <bool>         spi_miso;

    sc_signal<sc_uint<8> > spi_data_out;
    sc_signal<sc_uint<8> > spi_data_in;

    spi_master spi;

    void amba_slave()
    {
        static bool wr_flag = false;
        static sc_uint<32> wr_addr = 0;

        enable &&= spi_ss;

        if (!hresetn_i.read()) {
            wr_flag = false;
            wr_addr = 0;

            last_spi = 0;
            enabled  = false;
        } else if (hclk_i.read() && hsel_i.read()) {
            if (wr_flag) {
                data_in = hwdata_bi.read();
                enable  = true;
                wr_flag = false;
            }
            if (hwrite_i.read()) {
                wr_flag = true;
                wr_addr = haddr_bi.read();
            } else {
                hrdata_bo = !spi_ss << 3 | (spi_ss ? last_spi : data_out)
            }
        }
    }

    SC_CTOR(amba_spi): spi("SPI master")
    {
        SC_METHOD(amba_slave);
        sensitive << hclk_i.pos() << hresetn_i.pos();

        spi.clk(hclk_i);
        spi.rst(hresetn_i);
        spi.enable(enable);
        spi.miso(spi_miso);
        spi.mosi(spi_mosi);
        spi.sclk(spi_sclk);
        spi.ss(spi_ss);
        spi.data_in(data_in);
        spi.data_out(data_out);
    }

    private:
        sc_uint<8> last_spi;
        bool enable;
};

#endif // amba_spi_h_INCLUDED

