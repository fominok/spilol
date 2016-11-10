#include "amba_3_lite_discrete_adapter.h"
#include "amba_3_lite.h"
#include "amba_3_lite_pmodoled_adapter.h"
#include "discrete.h"
#include "pmodoled.h"

#include <stdio.h>

int haddr_w_cb(void *data, uint32_t addr) {
        printf("Setting address: %u\n", addr);
}

int hwdata_w_cb(void *data, uint32_t value) {
        printf("Writing value:   %u\n", value);
}

int hrdata_r_cb(void *data, uint32_t *value) {
        *value = 0x1337;
        printf("Reading value.\n");
}

int hwrite_w_cb(void *data, bool do_write) {
        printf("Setting mode to %s.\n", do_write ? "writing" : "reading");
}

int wait_posedge(void *data) {
        printf("Posedge.\n");
}

int main() {
        struct discrete_drv discrete;
        struct pmodoled_drv pmodoled;
        struct amba_3_lite_drv amba_3_lite;
        struct amba_3_lite_discrete_adapter a3d;
        struct amba_3_lite_pmodoled_adapter a3p;

        amba_3_lite.haddr_w_cb = haddr_w_cb;
        amba_3_lite.hwdata_w_cb = hwdata_w_cb;
        amba_3_lite.hrdata_r_cb = hrdata_r_cb;
        amba_3_lite.hwrite_w_cb = hwrite_w_cb;
        amba_3_lite.wait_posedge = wait_posedge;

        amba_3_lite_discrete_adapter_init(&a3d, &discrete, &amba_3_lite, 0x1);
        amba_3_lite_pmodoled_adapter_init(&a3p, &pmodoled, &amba_3_lite, 0x2);

        return 0;
}

