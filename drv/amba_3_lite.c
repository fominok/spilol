#include "amba_3_lite.h"

static int begin(struct amba_3_lite_drv *self, uint32_t addr, bool do_write) {
        self->wait_posedge(self->data);
        self->haddr_w_cb(self->data, addr);
        self->hwrite_w_cb(self->data, do_write);
        return 0;
}

static int end(struct amba_3_lite_drv *self) {
        self->wait_posedge(self->data);
        self->haddr_w_cb(self->data, 0);
        self->hwrite_w_cb(self->data, false);
        return 0;
}

int amba_3_lite_write_word(struct amba_3_lite_drv *self, uint32_t addr,
                uint32_t write) {
        begin(self, addr, true);
        self->hwdata_w_cb(self->data, write);
        end(self);
        return 0;
}

int amba_3_lite_read_word(struct amba_3_lite_drv *self, uint32_t addr,
                uint32_t *read) {
        begin(self, addr, false);
        self->wait_posedge(self->data);
        self->hrdata_r_cb(self->data, read);
        end(self);
        return 0;
}

