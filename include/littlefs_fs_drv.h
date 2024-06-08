#pragma once

/*********************
 *      INCLUDES
 *********************/
#include <Arduino.h>
#include <lvgl.h>
#include "FS.h"
#include <LittleFS.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct ArduinoEspLittleFile {
    fs::File file;
} ArduinoEspLittleFile;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_littlefs_fs_init(char letter);

/**********************
 *      MACROS
 **********************/