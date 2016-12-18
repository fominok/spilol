#ifndef amba_3_lite_spi_adapter_h_INCLUDED
#define amba_3_lite_spi_adapter_h_INCLUDED

#include "spi.h"
#include "amba_3_lite.h"

struct amba_3_lite_spi_adapter {
    struct amba_3_lite_drv *amba_3_lite;
    uint16_t child_address;
};

void amba_3_lite_spi_adapter_init(struct amba_3_lite_spi_adapter *,
                                  struct spi_drv *,
                                  struct amba_3_lite_drv *,
                                  uint16_t child_address);

int amba_3_lite_spi_adapter_write_byte(void *, uint8_t);
int amba_3_lite_spi_adapter_read_byte(void *, uint8_t*);
int amba_3_lite_spi_adapter_is_busy(void *, bool*);

#endif // amba_3_lite_spi_adapter_h_INCLUDED

