#include "sample.h"

#include "amba_3_lite_discrete_adapter.h"
#include "amba_3_lite.h"
#include "amba_3_lite_pmodoled_adapter.h"
#include "discrete.h"
#include "pmodoled.h"

void sample(struct amba_3_lite_drv *amba_3_lite) {
        struct discrete_drv discrete;
        struct pmodoled_drv pmodoled;

        struct amba_3_lite_discrete_adapter a3d;
        struct amba_3_lite_pmodoled_adapter a3p;

        amba_3_lite_discrete_adapter_init(&a3d, &discrete, amba_3_lite, 0x1);
        amba_3_lite_pmodoled_adapter_init(&a3p, &pmodoled, amba_3_lite, 0x2);

        bool do_exit = false;
        do {
                uint16_t switches;
                discrete_get_switches(&discrete, &switches);
                if (switches & 1) {
                        pmodoled_power_on(&pmodoled);
                } else {
                        pmodoled_power_on(&pmodoled);
                }
                pmodoled_set_brightness(&pmodoled, (switches & 0x3C) >> 2);
                pmodoled_set_inverted(&pmodoled, switches & (1 << 10));
                pmodoled_set_flipped(&pmodoled, switches & (1 << 11));
                pmodoled_set_horis_scroll_speed(&pmodoled,
                                (switches & 0x3000) >> 6);
                pmodoled_set_vert_speed_component(&pmodoled,
                                (switches & 0xC000) >> 8);
                if (!switches) {
                        do_exit = true;
                }
        } while (!do_exit);
        pmodoled_power_off(&pmodoled);

        uint16_t v1;
        // discrete_get_diods(&discrete, &v1);
        pmodoled_set_inverted(&pmodoled, 1);

}
