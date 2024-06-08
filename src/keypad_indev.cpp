#include "keypad_indev.h"

lv_indev_t *keypad_indev;


void keypad_read(lv_indev_t * indev, lv_indev_data_t*data);

void keypad_indev_init(void)
{
    pinMode(BUTTON_RIGHT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_ENTER_PIN, INPUT_PULLUP);
    pinMode(BUTTON_ESC_PIN, INPUT_PULLUP);

    keypad_indev = lv_indev_create();
    lv_indev_set_type(keypad_indev, LV_INDEV_TYPE_KEYPAD);
    lv_indev_set_read_cb(keypad_indev, keypad_read);
}

void keypad_read(lv_indev_t * indev, lv_indev_data_t*data)
{
    static uint8_t lastKey = 0;
    if (digitalRead(BUTTON_RIGHT_PIN) == LOW)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_NEXT;
        lastKey = LV_KEY_NEXT;
    }
    else if (digitalRead(BUTTON_LEFT_PIN) == LOW)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_PREV;
        lastKey = LV_KEY_PREV;
    } else if (digitalRead(BUTTON_ENTER_PIN) == LOW)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_ENTER;
        lastKey = LV_KEY_ENTER;
    }
    else if (digitalRead(BUTTON_ESC_PIN) == LOW)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_ESC;
        lastKey = LV_KEY_ESC;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
        data->key = lastKey;
    }
}
