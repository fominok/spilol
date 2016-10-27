#include "spi.h"
#include <stdlib.h>

int spi_read_write_byte(struct spi_drv *spi, uint8_t write, uint8_t *read) {
        spi->mosi_w_cb(spi->acc, write);
        if (read)
                spi->miso_r_cb(spi->acc, read);
        return spi->tx(spi->acc);
}

int spi_read_byte(struct spi_drv *spi, uint8_t *read) {
        return spi_read_write_byte(spi, 0x0, read);
}

int spi_write_byte(struct spi_drv *spi, uint8_t write) {
        return spi_read_write_byte(spi, write, NULL);
}

