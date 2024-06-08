#pragma once

#include <Arduino.h>
#include <lvgl.h>

#define BUTTON_RIGHT_PIN GPIO_NUM_33
#define BUTTON_LEFT_PIN GPIO_NUM_32
#define BUTTON_ENTER_PIN GPIO_NUM_35
#define BUTTON_ESC_PIN GPIO_NUM_25

extern lv_indev_t * keypad_indev;

void keypad_indev_init(void);