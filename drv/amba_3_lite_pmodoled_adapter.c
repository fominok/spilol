#include "amba_3_lite_pmodoled_adapter.h"

void amba_3_lite_pmodoled_adapter_init(
                struct amba_3_lite_pmodoled_adapter *self,
                struct pmodoled_drv *pmodoled,
                struct amba_3_lite_drv *amba_3_lite,
                uint8_t child_address) {
        pmodoled->data = self;
        pmodoled->write_word = amba_3_lite_pmodoled_adapter_write_word;
        self->amba_3_lite = amba_3_lite;
        self->child_address = child_address;
        pmodoled_config_init(&pmodoled->config);
}

int amba_3_lite_pmodoled_adapter_write_word(void *data, uint16_t addr,
                uint32_t value) {
        struct amba_3_lite_pmodoled_adapter *adapter = data;
        struct amba_3_lite_drv *amba_3_lite = adapter->amba_3_lite;
        uint32_t address = ((uint32_t)adapter->child_address << 16) | addr;
        uint32_t word;
        do {
                amba_3_lite_read_word(amba_3_lite, address, &word);
        } while (word);
        amba_3_lite_write_word(amba_3_lite, address, value);
}

