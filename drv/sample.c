#include "sample.h"

#include "amba_3_lite_discrete_adapter.h"
#include "amba_3_lite.h"
#include "amba_3_lite_pmodoled_adapter.h"
#include "discrete.h"
#include "pmodoled.h"

#include <unistd.h>

void sample(struct amba_3_lite_drv *amba_3_lite) {
        struct discrete_drv discrete;
        struct pmodoled_drv pmodoled;

        struct amba_3_lite_discrete_adapter a3d;
        struct amba_3_lite_pmodoled_adapter a3p;

        amba_3_lite_discrete_adapter_init(&a3d, &discrete, amba_3_lite, 0x1);
        amba_3_lite_pmodoled_adapter_init(&a3p, &pmodoled, amba_3_lite, 0x2);

        uint32_t letter[1][63] = {
                { 3 }
        };

        int8_t letter_idx = -1;
        bool is_on = false;

        bool do_exit = false;
        do {
                uint16_t switches;
                discrete_get_switches(&discrete, &switches);
                if (!(switches & 1)) {
                        if (!is_on)
                                pmodoled_power_on(&pmodoled);
                        is_on = true;
                } else {
                        if (is_on)
                                pmodoled_power_off(&pmodoled);
                        letter_idx = -1;
                        is_on = false;
                }
                uint8_t new_idx = (switches >> 1) & 0x1F;
                if (is_on && new_idx != letter_idx) {
                        size_t i;
                        for (i = 0; i < sizeof(letter[new_idx]); ++i) {
                                pmodoled_put_column(&pmodoled, i,
                                                letter[new_idx][i]);
                        }
                        letter_idx = new_idx;
                }

                pmodoled_set_brightness(&pmodoled, (switches >> 2) & 0xF0);
                pmodoled_set_inverted(&pmodoled, switches & (1 << 10));
                pmodoled_set_flipped(&pmodoled, switches & (1 << 11));
                pmodoled_set_horis_scroll_speed(&pmodoled,
                                (switches & 0x3000) >> 6);
                pmodoled_set_vert_speed_component(&pmodoled,
                                (switches & 0xC000) >> 8);

                discrete_set_diods(&discrete, switches);
                if (!switches) {
                        do_exit = true;
                }
        } while (!do_exit);
        pmodoled_power_off(&pmodoled);
}
