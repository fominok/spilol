#pragma once
#include <stdint.h>
#include <stdbool.h>

struct discrete_drv {
        int (*read)(void *, uint16_t addr, uint16_t *value);
        int (*write)(void *, uint16_t addr, uint16_t value);
        void *data;
};

int discrete_get_diods(struct discrete_drv *, uint16_t *values);
int discrete_get_switches(struct discrete_drv *, uint16_t *values);
int discrete_set_diods(struct discrete_drv *, uint16_t values);

