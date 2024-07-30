// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "i2c_master.h"

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
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                                 KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,                                  KC_6,    KC_7,   KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,                                  KC_Y,    KC_U,   KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,                                  KC_H,    KC_J,   KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  KC_NO,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,                                  KC_N,    KC_M,   KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, MO(2),   KC_NO,
                 KC_LCTL,   KC_LALT,  KC_LGUI,    KC_SPC,        KC_NO, KC_NO, KC_NO,      MO(1),   KC_RGUI, KC_RALT, KC_RCTL, TG(3),         KC_NO,   KC_NO
    ),
    [1] = LAYOUT_mod2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   LALT(KC_LEFT), KC_UP,   LALT(KC_RIGHT), KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_NO,   KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   LGUI(KC_LEFT), KC_NO,   LGUI(KC_RIGHT), KC_NO,   KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_NO, KC_NO, KC_NO,     KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_NO, KC_NO
    ),
    [2] = LAYOUT_mod(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_UP,    KC_HOME, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   LALT(KC_LEFT), KC_UP,   LALT(KC_RIGHT), KC_LEFT, KC_RIGHT, KC_END,  KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   KC_LEFT,       KC_DOWN, KC_RIGHT,       KC_NO,   KC_DOWN,  KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_NO,   LGUI(KC_LEFT), KC_NO,   LGUI(KC_RIGHT), KC_NO,   KC_NO,    KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_NO, KC_NO, KC_NO,      KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_NO, KC_NO
    ),
    [3] = LAYOUT_conf(
        QK_BOOT, QK_REBOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,                    KC_NO, KC_NO, KC_NO,        KC_TRNS,       KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_NO,   KC_NO
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Mod1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Mod2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Config\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("N/A"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    // if (led_state.caps_lock || led_state.num_lock || led_state.scroll_lock) {
    //     oled_write_P(PSTR("-----\n"), false);
    // }
    oled_write_P(led_state.caps_lock ? PSTR("Cap") : PSTR("   "), false); //CAP
    oled_write_P(led_state.num_lock ? PSTR("Num") : PSTR("   "), false); //NUM
    oled_write_P(led_state.scroll_lock ? PSTR("Scr") : PSTR("   "), false); //SCR
    
    return false;
}
#endif
