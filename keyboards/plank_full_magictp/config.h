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

#define DEBOUNCE 3

// #define SERIAL_USART_FULL_DUPLEX
// #define SERIAL_USART_TX_PIN GP16
// #define SERIAL_USART_RX_PIN GP17

// #ifdef OLED_ENABLE
// https://github.com/qmk/qmk_firmware/blob/master/docs/platformdev_rp2040.md
#define I2C1_SDA_PIN  GP20
#define I2C1_SCL_PIN  GP21
#define I2C_DRIVER I2CD0
#define OLED_DISPLAY_128X64

#define OLED_BRIGHTNESS 128

// #undef FORCE_NKRO
// #define FORCE_NKRO
