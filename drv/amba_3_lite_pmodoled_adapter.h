#include <stdint.h>
#include "amba_3_lite.h"
#include "pmodoled.h"

struct amba_3_lite_pmodoled_adapter {
        struct amba_3_lite_drv *amba_3_lite;
        uint16_t child_address;
};

void amba_3_lite_pmodoled_init(struct amba_3_lite_pmodoled_adapter *,
                struct pmodoled_drv *, struct amba_3_lite_drv *,
                uint8_t child_address);

int amba_3_lite_pmodoled_adapter_write_word(void *, uint16_t addr,
                uint32_t value);

