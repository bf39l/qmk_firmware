// Copyright 2024 Bo Liu (@bf39L)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// ------------------
#define QUICK_TAP_TERM 0

// #define SERIAL_SLAVE_BUFFER_LENGTH  ((MATRIX_ROWS)/2)
// #define SERIAL_MASTER_BUFFER_LENGTH ((MATRIX_ROWS)/2)

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS


/* key matrix size */
// Rows are doubled-up
// #define MATRIX_ROWS 10 // 5 row original
// #define MATRIX_ROW_PINS {GP10, GP11, GP12, GP13, GP14}

// wiring of each half
// #define MATRIX_COLS 7
// #define MATRIX_COL_PINS {GP2, GP3, GP4, GP5, GP6, GP8, GP9}

/* COL2ROW, ROW2COL*/
// #define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 3

// #ifdef OLED_ENABLE
// https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md
#define I2C1_SDA_PIN  GP20
#define I2C1_SCL_PIN  GP21
#define I2C_DRIVER I2CD0
#define OLED_DISPLAY_128X64

#define OLED_BRIGHTNESS 128
// #define OLED_FONT_H "keyboards/bf39l_xbows/lib/glcdfont.c"
// #endif

// #define SERIAL_USART_FULL_DUPLEX
// #define SERIAL_USART_TX_PIN GP16
// #define SERIAL_USART_RX_PIN GP17

// #define HAL_USE_I2C TRUE
// #define HAL_USE_SIO TRUE
// #include_next <halconf.h>

// #include_next <mcuconf.h> // for i2c

#define POINTING_DEVICE_DEBUG
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// This enables transmitting the pointing device status
// to the master side of the split keyboard.
// The purpose of this feature is to enable use pointing
// devices on the slave side.

// #undef FORCE_NKRO
// #define FORCE_NKRO

// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_COMBINED
#define AZOTEQ_IQS5XX_TPS65
// #define AZOTEQ_IQS5XX_ADDRESS 0xE9
#define AZOTEQ_IQS5XX_TIMEOUT_MS 10
// #undef AZOTEQ_IQS5XX_WIDTH_MM
// #define AZOTEQ_IQS5XX_WIDTH_MM 63
// #undef AZOTEQ_IQS5XX_HEIGHT_MM
// #define AZOTEQ_IQS5XX_HEIGHT_MM 47
// #define POINTING_DEVICE_LEFT
// #define AZOTEQ_IQS5XX_ACTIVE

// #define AZOTEQ_IQS5XX_TPS65
// #undef AZOTEQ_IQS5XX_WIDTH_MM
// #define AZOTEQ_IQS5XX_WIDTH_MM 77
// #undef AZOTEQ_IQS5XX_HEIGHT_MM
// #define AZOTEQ_IQS5XX_HEIGHT_MM 48
#define AZOTEQ_IQS5XX_TAP_ENABLE true
#define AZOTEQ_IQS5XX_TWO_FINGER_TAP_ENABLE true
#define AZOTEQ_IQS5XX_ZOOM_ENABLE true
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
#define AZOTEQ_IQS5XX_SCROLL_ENABLE true







/*

// ------------------
#define QUICK_TAP_TERM 0

// #define MASTER_LEFT

// COL2ROW, ROW2COL
// #define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 3

#define I2C0_SDA_PIN  GP20
#define I2C0_SCL_PIN  GP21
#define I2C1_SDA_PIN  GP20
#define I2C1_SCL_PIN  GP21
#define I2C_DRIVER I2CD0

// #define HAL_USE_I2C TRUE
#include_next <halconf.h>

#include_next <mcuconf.h> // for i2c
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
// #undef RP_I2C_USE_I2C1
// #define RP_I2C_USE_I2C1 TRUE

// #define SPLIT_POINTING_ENABLE
// This enables transmitting the pointing device status
// to the master side of the split keyboard.
// The purpose of this feature is to enable use pointing
// devices on the slave side.

// pointing device
#define CIRQUE_PINNACLE_ADDR 0x0A
// #define POINTING_DEVICE_LEFT
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_DEBUG


 // Feature disable options
 // These options are also useful to firmware size reduction.

// disable debug print 
//#define NO_DEBUG

// disable print
//#define NO_PRINT

// disable action features
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

*/