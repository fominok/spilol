#include "amba_3_lite_pmodoled_adapter.h"

void amba_3_lite_pmodoled_init(struct pmodoled_drv *pmodoled,
                struct amba_3_lite_drv *amba_3_lite) {
        pmodoled->data = amba_3_lite;
        pmodoled->write_word = amba_3_lite_pmodoled_adapter_write_word;
        pmodoled_config_init(&pmodoled->config);
}

int amba_3_lite_pmodoled_adapter_write_word(void *data, uint32_t addr,
                uint32_t value) {
        struct amba_3_lite_drv *amba_3_lite = data;
        uint32_t word;
        do {
                amba_3_lite_read_word(amba_3_lite, addr, &word);
        } while (word);
        amba_3_lite_write_word(amba_3_lite, addr, value);
}

