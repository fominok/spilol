#include <string.h>
#include "spi.h"
#include "amba_3_lite.h"

enum amba_3_spi_cmd {
        A3SPI_WR_MOSI,
        A3SPI_RD_MISO,
        A3SPI_START,
};

struct amba_3_lite_spi_acc {
        struct amba_3_lite_drv amba_3_lite;
        struct spi_drv spi;
        uint16_t slave;
        uint8_t *miso;
};

int amba_3_lite_spi_read_write_byte(struct amba_3_lite_spi_acc *,
                uint8_t write, uint8_t *read);
int amba_3_lite_spi_read_byte(struct amba_3_lite_spi_acc *, uint8_t *read);
int amba_3_lite_spi_write_byte(struct amba_3_lite_spi_acc *, uint8_t *write);

int amba_3_lite_spi_init(struct amba_3_lite_spi_acc *,
                const struct amba_3_lite_drv *, uint16_t slave);

