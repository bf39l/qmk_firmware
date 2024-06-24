// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "i2c_master.h"
#include "debug.h"

#define TIMEOUT 500

// TODO: remove patch
#ifdef PROTOCOL_CHIBIOS
#    pragma message("ChibiOS is currently 'best effort' and might not report accurate results")
#endif

#ifdef PROTOCOL_CHIBIOS
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    L: (r0,c0) DRAG_SCROLL (r0,c1) KC_P6
       (r1,c0) KC_P1       (r1,c1) KC_P2
    R: (r0,c0) KC_MS_BTN1  (r0,c1) KC_MS_BTN2
       (r1,c0) KC_P3       (r1,c1) KC_P4

       LALT(KC_RIGHT)
       LT(2, KC_SPC)
    */

    [0] = LAYOUT_def(

        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_RBRC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_ESC,
        KC_RSFT, KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI,        KC_SPC,        MO(2)

    ),
    [1] = LAYOUT_fn(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT_mos(
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(3),
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT_conf(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
        NK_ON,   NK_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS
    )
};

#include "print.h"

void do_scan(void) {
    uint8_t nDevices = 0;

    dprintf("Scanning...\n");

    for (uint8_t address = 1; address < 127; address++) {
        // The i2c_scanner uses the return value of
        // i2c_ping_address to see if a device did acknowledge to the address.
        i2c_status_t error = i2c_ping_address(address << 1, TIMEOUT);
        if (error == I2C_STATUS_SUCCESS) {
            dprintf("  I2C device found at address 0x%02X\n", address);
            nDevices++;
        } else {
            // dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
        }
    }

    if (nDevices == 0)
        dprintf("No I2C devices found\n");
    else
        dprintf("done\n");
}

uint16_t scan_timer = 0;

void matrix_scan_user(void) {
    if (timer_elapsed(scan_timer) > 5000) {
        do_scan();
        scan_timer = timer_read();
    }
}

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;

    i2c_init();
    scan_timer = timer_read();
}



////////////////////////////////////////////////////
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif 
//     return true;
// }

// uint16_t ping_timer = 0;
// uint8_t address = 255; //126;
// void do_scan(void) {
//     uint8_t nDevices = 0;

//     dprintf("Scanning...\n");
//     if (address >= 0) {
//         i2c_status_t error = i2c_ping_address(address << 1, TIMEOUT);
//         if (error == I2C_STATUS_SUCCESS) {
//             dprintf("  I2C device found at address 0x%02X\n", address);
            
//             nDevices++;
//         } else {
//             dprintf("  Unknown error (%u) at address 0x%02X\n", error, address);
//         }
//     }
//     address--;

//     if (nDevices == 0 && address < 0)
//         dprintf("No I2C devices found\n");
//     else
//         dprintf("done address: %d\n", address);
// }

// uint16_t scan_timer = 0;

// void matrix_scan_user(void) {
//     if (timer_elapsed(scan_timer) > 3000) {
//         do_scan();
//         scan_timer = timer_read();
//     }
// }

// void keyboard_post_init_user(void) {
//     debug_enable = true;
//     debug_matrix = true;

//     i2c_init();
//     scan_timer = timer_read();
// }
////////////////////////////////////////////////////


// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     dprintf("pointing_device_task_user\n");

//     return mouse_report;
// }

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif