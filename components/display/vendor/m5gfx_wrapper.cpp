#include "LGFX_ESP32_ELECROW.h"
#include "m5gfx_wrapper.h"

extern "C" void init_m5gfx_display() {
    lcd.init();
    lcd.fillScreen(0);
}

extern "C" void m5gfx_write_pixels(int32_t x1, int32_t y1,
                                   int32_t x2, int32_t y2,
                                   uint16_t *color_p) {
    lcd.startWrite();
    lcd.setAddrWindow(x1, y1, x2 - x1 + 1, y2 - y1 + 1);
    lcd.pushPixels(color_p, (x2 - x1 + 1) * (y2 - y1 + 1));
    lcd.endWrite();
}
