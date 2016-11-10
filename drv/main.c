#include "amba_3_lite_discrete_adapter.h"
#include "amba_3_lite.h"
#include "amba_3_lite_pmodoled_adapter.h"
#include "discrete.h"
#include "pmodoled.h"

#include "sample.h"

#include <stdio.h>

int haddr_w_cb(void *data, uint32_t addr) {
        printf("Setting address: %x\n", addr);
}

int hwdata_w_cb(void *data, uint32_t value) {
        printf("Writing value:   %x\n", value);
}

int hrdata_r_cb(void *data, uint32_t *value) {
        *value = 0x0;
        printf("Reading value.\n");
}

int hwrite_w_cb(void *data, bool do_write) {
        printf("Setting mode to %s.\n", do_write ? "writing" : "reading");
}

int wait_posedge(void *data) {
        printf("Posedge.\n");
}

int main() {
        struct amba_3_lite_drv amba_3_lite;

        amba_3_lite.haddr_w_cb = haddr_w_cb;
        amba_3_lite.hwdata_w_cb = hwdata_w_cb;
        amba_3_lite.hrdata_r_cb = hrdata_r_cb;
        amba_3_lite.hwrite_w_cb = hwrite_w_cb;
        amba_3_lite.wait_posedge = wait_posedge;

        sample(&amba_3_lite);

        return 0;
}

