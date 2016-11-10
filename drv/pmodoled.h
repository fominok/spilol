#include <stdint.h>
#include <stdbool.h>

struct pmodoled_config {
        bool inverted;
        bool flipped;
        uint8_t brightness;
        uint8_t horis_scroll_speed;
        uint8_t vert_speed_component;
};

void pmodoled_config_init(struct pmodoled_config *config);

struct pmodoled_drv {
        int (*write_word)(void *, uint16_t addr, uint32_t value);
        void *data;
        struct pmodoled_config config;
};

int pmodoled_put_pixel(struct pmodoled_drv *, uint8_t x, uint8_t y, bool on);
int pmodoled_put_column(struct pmodoled_drv *, uint8_t x, uint32_t column);
int pmodoled_power_on(struct pmodoled_drv *);
int pmodoled_power_off(struct pmodoled_drv *);
int pmodoled_set_inverted(struct pmodoled_drv *, bool);
int pmodoled_set_flipped(struct pmodoled_drv *, bool);
int pmodoled_set_brightness(struct pmodoled_drv *, uint8_t);
int pmodoled_set_horis_scroll_speed(struct pmodoled_drv *, uint8_t);
int pmodoled_set_vert_speed_component(struct pmodoled_drv *, uint8_t);

