#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "littlefs_fs_drv.h"
#include "keypad_indev.h"

#define TFT_HOR_RES 320
#define TFT_VER_RES 240

void init_lvgl();
void init_ui();
uint32_t my_tick_get_cb(void);

void setup()
{
    init_lvgl();
    init_ui();
}

void loop()
{
    lv_timer_handler();
}

void init_lvgl()
{
    lv_init();
    lv_tick_set_cb(my_tick_get_cb);
    lv_littlefs_fs_init('S');
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10)
    static uint8_t draw_buf[DRAW_BUF_SIZE];
    static lv_display_t *disp;
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
    /*
        Workaround for misaligned display rotation in lvgl and TFT_eSPI configuration.
        lv_tft_espi_create creates a TFT_eSPI object with a default rotation of 3 (landscape, flipped).
        It causes problems displaying the UI correctly.
    */ 
    typedef struct tft_espi_wrapper
    {
        TFT_eSPI *tft;
    } tft_espi_wrapper;
    tft_espi_wrapper *dsc = (tft_espi_wrapper *)lv_display_get_driver_data(disp);
    dsc->tft->setRotation(1); // Set the correct rotation to 1 (landscape)
    /*
        End of workaround
    */

    lv_display_set_default(disp);
    keypad_indev_init();
}

void init_ui()
{
    lv_disp_t *disp = lv_display_get_default();
    if (!disp)
    {
        return;
    }
    lv_theme_t *theme = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_display_set_theme(disp, theme);
    auto ui_MainScreen = lv_obj_create(NULL);
    lv_obj_set_width(ui_MainScreen, lv_pct(100));
    lv_obj_set_height(ui_MainScreen, lv_pct(100));
    lv_obj_set_flex_flow(ui_MainScreen, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_MainScreen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    auto ui_helloLabel = lv_label_create(ui_MainScreen);
    lv_obj_set_width(ui_helloLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_helloLabel, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_helloLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_helloLabel, "Hello, World!");

    lv_screen_load(ui_MainScreen);
}

uint32_t my_tick_get_cb(void) { return millis(); }
