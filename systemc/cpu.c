#include "cpu.h"
#include "../drv/sample.h"

static int haddr_w_cb(void *data, uint32_t addr) {
        cpu *c = static_cast<cpu *>(data);
        c->haddr.write(addr);
}

static int hwdata_w_cb(void *data, uint32_t value) {
        cpu *c = static_cast<cpu *>(data);
        c->hwdata.write(value);
}

static int hrdata_r_cb(void *data, uint32_t *value) {
        cpu *c = static_cast<cpu *>(data);
        *value = c->hrdata.read();
}

static int hwrite_w_cb(void *data, bool do_write) {
        cpu *c = static_cast<cpu *>(data);
        c->hwrite.write(do_write);
}

static int wait_posedge(void *data) {
        cpu *c = static_cast<cpu *>(data);
        c->pub_wait();
}

void cpu::pub_wait() {
        wait();
}

void cpu::app() {
        struct amba_3_lite_drv amba_3_lite;
        amba_3_lite.haddr_w_cb = haddr_w_cb;
        amba_3_lite.hwdata_w_cb = hwdata_w_cb;
        amba_3_lite.hrdata_r_cb = hrdata_r_cb;
        amba_3_lite.hwrite_w_cb = hwrite_w_cb;
        amba_3_lite.wait_posedge = wait_posedge;
        amba_3_lite.data = this;
        while (rst) {
            wait();
        }
        sample(&amba_3_lite);
}

