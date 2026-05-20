// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <math.h>
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    L: (r0,c0) DRAG_SCROLL (r0,c1) KC_P6
       (r1,c0) KC_P1       (r1,c1) KC_P2
    R: (r0,c0) KC_MS_BTN1  (r0,c1) KC_MS_BTN2
       (r1,c0) KC_P3       (r1,c1) KC_P4

       LALT(KC_RIGHT)
       LT(2, KC_SPC)
    */

    [0] = LAYOUT_qwe(

        KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  HYPR_T(KC_ESC),
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,
        MEH_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_RBRC,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 MO(3),
        KC_LCTL,        KC_NO, KC_NO,     KC_LALT, KC_LGUI,        KC_SPC,        KC_BSPC,


                        MEH_T(KC_ESC),  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
                        KC_BSLS,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_EQL,
                        KC_ESC,         KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
        TO(1),                          KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
        KC_ENT,  LT(2, KC_SPC),      KC_RGUI, KC_RALT,    KC_NO, KC_NO,               KC_RCTL

    ),
    [1] = LAYOUT_col(

        KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  MEH_T(KC_ESC),
        KC_TAB,         KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,  KC_LBRC,
        MEH_T(KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,  KC_RBRC,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 MO(3),
        KC_LCTL,        KC_NO, KC_NO,     KC_LALT, KC_LGUI,        KC_SPC,        KC_BSPC,


                        MEH_T(KC_ESC),  KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
                        KC_BSLS,        KC_J,    KC_L,    KC_U,    KC_Y,     KC_SCLN, KC_EQL,
                        KC_ESC,         KC_H,    KC_N,    KC_E,    KC_I,     KC_O,    KC_QUOT,
        TO(0),                          KC_K,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
        KC_ENT,  LT(2, KC_SPC),      KC_RGUI, KC_RALT,    KC_NO, KC_NO,               KC_RCTL

    ),
    [2] = LAYOUT_fn(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_DEL,

                 KC_TRNS,  KC_F6,   KC_F7,         KC_F8,    KC_F9,          KC_F10,  KC_F11,
                 KC_PGUP,  KC_HOME, LALT(KC_LEFT), KC_UP,    LALT(KC_RIGHT), KC_NUM,  KC_F12,
                 KC_PGDN,  KC_END,  KC_LEFT,       KC_DOWN,  KC_RIGHT,       KC_NO,   KC_TRNS,
        KC_TRNS,           KC_TRNS, LGUI(KC_LEFT), KC_NO,    LGUI(KC_RIGHT), KC_INS,  KC_TRNS,
        KC_TRNS, KC_TRNS,           KC_TRNS,       KC_TRNS,  KC_TRNS,        KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT_conf(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, DT_PRNT, TO(0),
        NK_ON,   NK_OFF,  KC_NO, KC_NO, KC_NO, KC_NO, DT_UP,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DT_DOWN,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO,

                 QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0),
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

#ifdef OLED_ENABLE
// static void render_logo(void) {
//     // static const char PROGMEM qmk_logo[] = {
//     //     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//     //     0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//     //     0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     // };

//     // oled_write_P(qmk_logo, false);
//     oled_set_cursor(0,1);
//     oled_write("Hello World!", false);
//     // oled_write_P(qmk_logo, false);
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// bool oled_task_user(void) {
//     render_logo();
//     return false;
// }

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Def-\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Col-\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Fnc-\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Con-\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("N/A"), false);
    }
    return false;

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock || led_state.num_lock || led_state.scroll_lock) {
        oled_write_P(PSTR("-----\n"), false);
    }
    oled_write_P(led_state.caps_lock ? PSTR("C") : PSTR(" "), false); //CAP
    oled_write_P(led_state.num_lock ? PSTR("N") : PSTR(" "), false); //NUM
    oled_write_P(led_state.scroll_lock ? PSTR("S") : PSTR(" "), false); //SCR
}
#endif
