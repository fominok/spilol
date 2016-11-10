#include "pmodoled.h"
#include <strings.h>

#define FLUSH_SETTING(s) \
        if (self->config.s ^ s) { self->config.s = s; flush_cfg(self); }
 

int flush_cfg(struct pmodoled_drv *self) {
        return self->write_word(self->data, 0x2004,
                        self->config.inverted                  |
                        self->config.flipped              << 1 |
                        self->config.brightness           << 2 |
                        self->config.horis_scroll_speed   << 6 |
                        self->config.vert_speed_component << 9 );
}

void pmodoled_config_init(struct pmodoled_config *config) {
        bzero(config, sizeof(struct pmodoled_config));
        config->brightness = 15;
}

int pmodoled_put_pixel(struct pmodoled_drv *self, uint8_t x, uint8_t y,
                bool on) {
        return self->write_word(self->data, (uint16_t)x << 5 | y, on);
}

int pmodoled_put_column(struct pmodoled_drv *self, uint8_t x, uint32_t col) {
        return self->write_word(self->data, (uint16_t)x << 2, col);
}

int pmodoled_power_on(struct pmodoled_drv *self) {
        self->write_word(self->data, 0x2000, 1);
        flush_cfg(self);
}

int pmodoled_power_off(struct pmodoled_drv *self) {
        self->write_word(self->data, 0x2000, 0);
}

int pmodoled_set_inverted(struct pmodoled_drv *self, bool inverted) {
        FLUSH_SETTING(inverted);
}

int pmodoled_set_flipped(struct pmodoled_drv *self, bool flipped) {
        FLUSH_SETTING(flipped);
}

int pmodoled_set_brightness(struct pmodoled_drv *self, uint8_t brightness) {
        brightness >>= 4;
        FLUSH_SETTING(brightness);
}

int pmodoled_set_horis_scroll_speed(struct pmodoled_drv *self,
                uint8_t horis_scroll_speed) {
        horis_scroll_speed >>= 5;
        FLUSH_SETTING(horis_scroll_speed);
}

int pmodoled_set_vert_speed_component(struct pmodoled_drv *self,
                uint8_t vert_speed_component) {
        vert_speed_component >>= 2;
        FLUSH_SETTING(vert_speed_component);
}

