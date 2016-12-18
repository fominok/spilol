#pragma once
#include <stdint.h>
#include <stdbool.h>

struct spi_drv {
        int (*write_byte)(void *, uint8_t);
        int (*read_byte) (void *, uint8_t*);
        int (*is_busy)   (void *, bool*);
        void *data;
};

int spi_write_byte_cansleep(struct spi_drv*, uint8_t);
int spi_read_byte_cansleep (struct spi_drv*, uint8_t*);
int spi_is_busy            (struct spi_drv*, bool*);
int spi_exchange           (struct spi_drv*, uint8_t, uint8_t*);
