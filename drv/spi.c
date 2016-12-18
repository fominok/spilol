#include "spi.h"

#define WAIT bool _b; do { self->is_busy(self->data, &_b); } while (_b);

int spi_write_byte_cansleep(struct spi_drv *self, uint8_t byte)
{
	WAIT;
	return self->write_byte(self->data, byte);
}

int spi_read_byte_cansleep(struct spi_drv *self, uint8_t *byte)
{
	WAIT;
	return self->read_byte(self->data, byte);
}

int spi_is_busy(struct spi_drv *self, bool *busy)
{
	WAIT;
	return self->is_busy(self->data, busy);
}

int spi_exchange(struct spi_drv *self, uint8_t in, uint8_t *out)
{
	self->write_byte(self->data, in);
	WAIT;
	return self->read_byte(self->data, out);
}
