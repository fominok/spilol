#include <stdint.h>

struct spi_drv {
        int (*mosi_w_cb)(void *, uint8_t mosi);
        int (*miso_r_cb)(void *, uint8_t *miso);
        int (*tx)(void *);
        void *acc;
};

int spi_read_write_byte(struct spi_drv *, uint8_t write, uint8_t *read);

int spi_read_byte(struct spi_drv *, uint8_t *read);
int spi_write_byte(struct spi_drv *, uint8_t write);

