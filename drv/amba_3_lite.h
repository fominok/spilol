#include <stdint.h>
#include <stdbool.h>

struct amba_3_lite_drv {
        int (*haddr_w_cb)(void *, uint32_t);
        int (*hwdata_w_cb)(void *, uint32_t);
        int (*hrdata_r_cb)(void *, uint32_t*);
        int (*hwrite_w_cb)(void *, bool);
        int (*wait_posedge)(void *);
        void *data;
};

int amba_3_lite_write_word(struct amba_3_lite_drv*, uint32_t addr,
                uint32_t write);
int amba_3_lite_read_word(struct amba_3_lite_drv*, uint32_t addr,
                uint32_t *read);

