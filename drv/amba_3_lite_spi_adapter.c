#include "amba_3_lite_spi_adapter.h"
#include <unistd.h>

void amba_3_lite_spi_adapter_init(struct amba_3_lite_spi_adapter *adapter,
                                 struct spi_drv *spi,
                                 struct amba_3_lite_drv *amba,
                                 uint16_t child_address)
{
	adapter->child_address = child_address;
	adapter->amba_3_lite = amba;
	spi->write_byte = amba_3_lite_spi_adapter_write_byte;
	spi->read_byte  = amba_3_lite_spi_adapter_read_byte;
	spi->is_busy    = amba_3_lite_spi_adapter_is_busy;
	spi->data       = adapter;
}

int amba_3_lite_spi_adapter_read_status(void *data, uint8_t *byte, bool *busy)
{
	struct amba_3_lite_spi_adapter *self = data;
	struct amba_3_lite_drv *amba_3_lite = self->amba_3_lite;
	uint32_t address = ((uint32_t)self->child_address << 16) | 0x4;
	uint32_t word;
	int retcode = amba_3_lite_read_word(amba_3_lite, address, &word);
	if (byte) {
		*byte = word & 255;
	}
	if (busy) {
		*busy = word & 256;
	}
	return retcode;
}

int amba_3_lite_spi_adapter_is_busy(void *data, bool *busy)
{
	return amba_3_lite_spi_adapter_read_status(data, NULL, busy);
}

int amba_3_lite_spi_adapter_read_byte(void *data, uint8_t *byte)
{
	return amba_3_lite_spi_adapter_read_status(data, byte, NULL);
}

int amba_3_lite_spi_adapter_write_byte(void *data, uint8_t byte)
{
	struct amba_3_lite_spi_adapter *self = data;
	struct amba_3_lite_drv *amba_3_lite = self->amba_3_lite;
	uint32_t address = ((uint32_t)self->child_address << 16);
	return amba_3_lite_write_word(amba_3_lite, address, byte);
}
