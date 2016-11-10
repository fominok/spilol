#include "discrete.h"

int discrete_get_diods(struct discrete_drv *self, uint16_t *values) {
        return self->read(self->data, 0x0000, values);
}

int discrete_get_switches(struct discrete_drv *self, uint16_t *values) {
        return self->read(self->data, 0x0004, values);
}

int discrete_set_diods(struct discrete_drv *self, uint16_t values) {
        return self->write(self->data, 0x0000, values);
}


