#include <stdint.h>
#include "amba_3_lite.h"
#include "pmodoled.h"

void amba_3_lite_pmodoled_init(struct pmodoled_drv *,
                struct amba_3_lite_drv *);

int amba_3_lite_pmodoled_adapter_write_word(void *, uint32_t addr,
                uint32_t value);

