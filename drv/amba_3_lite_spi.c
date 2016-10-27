#include "amba_3_lite_spi_acc.h"

static int mosi_w_cb(void *data, uint8_t mosi) {
        struct amba_3_lite_spi_acc *self = (struct amba_3_lite_spi_acc *)data;
        amba_3_lite_write_word(&self->amba_3_lite, self->slave, A3SPI_WR_MOSI);
        amba_3_lite_write_word(&self->amba_3_lite, self->slave, mosi);
        return 0;
}

static int miso_r_cb(void *data, uint8_t *miso) {
        struct amba_3_lite_spi_acc *self = (struct amba_3_lite_spi_acc *)data;
        self->miso = miso;
        return 0;
}

static int tx(void *data) {
        uint32_t miso;
        struct amba_3_lite_spi_acc *self = (struct amba_3_lite_spi_acc *)data;
        amba_3_lite_write_word(&self->amba_3_lite, self->slave, A3SPI_START);
        if (self->miso) {
                amba_3_lite_write_word(&self->amba_3_lite, self->slave,
                                A3SPI_RD_MISO);
                amba_3_lite_read_word(&self->amba_3_lite, self->slave, &miso);
                *self->miso = (uint32_t)miso;
        }
        self->miso = NULL;
}

int amba_3_lite_spi_init(struct amba_3_lite_spi_acc *self,
                const struct amba_3_lite_drv *amba_3_lite, uint16_t slave) {
        self->slave = slave;
        memcpy(&self->amba_3_lite, amba_3_lite,
                        sizeof(struct amba_3_lite_drv));
        self->spi.mosi_w_cb = mosi_w_cb;
        self->spi.miso_r_cb = miso_r_cb;
        self->spi.tx = tx;
        self->spi.acc = self;
        return 0;
}

