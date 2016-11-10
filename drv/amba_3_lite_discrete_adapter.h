#include <stdint.h>
#include "amba_3_lite.h"
#include "discrete.h"

struct amba_3_lite_discrete_adapter {
        struct amba_3_lite_drv *amba_3_lite;
        uint16_t child_address;
};

void amba_3_lite_discrete_init(struct amba_3_lite_discrete_adapter *,
                struct discrete_drv *, struct amba_3_lite_drv *,
                uint8_t child_address);

int amba_3_lite_discrete_adapter_write(void *, uint16_t addr, uint16_t value);
int amba_3_lite_discrete_adapter_read(void *, uint16_t addr, uint16_t *value);

