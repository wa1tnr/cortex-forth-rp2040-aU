// rp2040_reflash.inc

#include "pico/bootrom.h"
void reflash(void) {  /*  --  */
    reset_usb_boot(0, 0);
}
