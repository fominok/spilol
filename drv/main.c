#include "amba_3_lite_discrete_adapter.h"
#include "amba_3_lite.h"
#include "amba_3_lite_pmodoled_adapter.h"
#include "discrete.h"
#include "pmodoled.h"

int main() {
        struct discrete_drv discrete;
        struct pmodoled_drv pmodoled;
        struct amba_3_lite_drv amba_3_lite;
        struct amba_3_lite_discrete_adapter a3d;
        struct amba_3_lite_pmodoled_adapter a3p;
        amba_3_lite_discrete_adapter_init(&a3d, &discrete, &amba_3_lite, 0x1);
        amba_3_lite_pmodoled_adapter_init(&a3p, &pmodoled, &amba_3_lite, 0x2);
        // All that remains is to fill `amba_3_lite`, and functions on
        // `discrete` and `pmodoled` can be called.
        return 0;
}

