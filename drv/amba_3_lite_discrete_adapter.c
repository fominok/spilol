#include "amba_3_lite_discrete_adapter.h"

void amba_3_lite_discrete_init(struct amba_3_lite_discrete_adapter *self,
                struct discrete_drv *discrete,
                struct amba_3_lite_drv *amba_3_lite,
                uint8_t child_address) {
        discrete->data = self;
        discrete->write = amba_3_lite_discrete_adapter_write;
        discrete->read = amba_3_lite_discrete_adapter_read;
        self->amba_3_lite = amba_3_lite;
        self->child_address = child_address;
}

int amba_3_lite_discrete_adapter_read(void *data, uint16_t addr,
                uint16_t *value) {
        struct amba_3_lite_discrete_adapter *adapter = data;
        struct amba_3_lite_drv *amba_3_lite = adapter->amba_3_lite;
        uint32_t address = ((uint32_t)adapter->child_address << 16) | addr;
        uint32_t retval;
        amba_3_lite_read_word(amba_3_lite, address, &retval);
        *value = (uint16_t)retval;
}

int amba_3_lite_discrete_adapter_write(void *data, uint16_t addr,
                uint16_t value) {
        struct amba_3_lite_discrete_adapter *adapter = data;
        struct amba_3_lite_drv *amba_3_lite = adapter->amba_3_lite;
        uint32_t address = ((uint32_t)adapter->child_address << 16) | addr;
        return amba_3_lite_write_word(amba_3_lite, address, value);
}

