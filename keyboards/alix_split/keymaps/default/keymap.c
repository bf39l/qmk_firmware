// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <math.h>
#include QMK_KEYBOARD_H

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
    TG_PRECISE,
};

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
        KC_RSFT, KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI,        KC_SPC,        MO(2),


                     KC_NO,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                     KC_BSLS,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
                     KC_QUOT,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_NO,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        DRAG_SCROLL, MO(1),               KC_RGUI, KC_RALT, KC_RCTL, TO(1),   TO(2)

    ),
    [1] = LAYOUT_fn(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, DRAG_SCROLL,

                 KC_F12,  KC_F6,   KC_F7,         KC_F8,    KC_F9,           KC_F10,  KC_TRNS,
                 KC_NUM,  KC_NO,   LALT(KC_LEFT), KC_UP,    LALT(KC_RIGHT),  KC_PGUP, KC_HOME,
                 KC_INS,  KC_NO,   KC_LEFT,       KC_DOWN,  KC_RIGHT,        KC_PGDN, KC_END,
        KC_NO,            KC_NO,   LGUI(KC_LEFT), KC_NO,    LGUI(KC_RIGHT),  KC_NO,   KC_TRNS,
        KC_TRNS, KC_TRNS,          TG_PRECISE,    KC_TRNS,  KC_TRNS,         TO(0),   KC_TRNS
    ),
    [2] = LAYOUT_mos(
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(3),
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG_PRECISE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,

                                KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_MS_BTN3,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,                           DRAG_SCROLL, TG_PRECISE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MS_BTN1, KC_MS_BTN2,                       KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, TO(0)
    ),
    [3] = LAYOUT_conf(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
        NK_ON,   NK_OFF,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,

                 QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
bool set_scrolling = false;
bool precise_on = false;

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Def-\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Fnc-\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Mos-\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Con-\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("N/A"), false);
    }

    oled_write_ln_P(PSTR(""), false);
    oled_write_P(PSTR("*Mos*\n"), false);
    oled_write_P(set_scrolling ? PSTR("MS\n") : PSTR("    \n"), false); //MouseScroll
    oled_write_P(precise_on ? PSTR("MP\n") : PSTR("    \n"), false); //MousePrecise
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

int precise_counter = 0;
layer_state_t layer_state_set_user(layer_state_t state) {
    // switch (get_highest_layer(state)) {
    // case _RAISE:
    //     rgblight_setrgb (0x00,  0x00, 0xFF);
    //     break;
    // case _LOWER:
    //     rgblight_setrgb (0xFF,  0x00, 0x00);
    //     break;
    // case _PLOVER:
    //     rgblight_setrgb (0x00,  0xFF, 0x00);
    //     break;
    // case _ADJUST:
    //     rgblight_setrgb (0x7A,  0x00, 0xFF);
    //     break;
    // default: //  for any other layers, or the default layer
    //     rgblight_setrgb (0x00,  0xFF, 0xFF);
    //     break;
    // }
    switch (get_highest_layer(state)) {
        case 2:
            if (!precise_on && precise_counter == 0) {
                precise_on = true;
                precise_counter = 1;
            }
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            precise_on = false;
            precise_counter = 0;
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            if (record->event.pressed) {
                // Do something when pressed
                set_scrolling = true;
            } else {
                // Do something else when release
                set_scrolling = false;
            }
            break;
            // return false;
        case TG_PRECISE:
            precise_on = !precise_on;
            break;
        default:
            break; // Process all other keycodes normally
    }

    return true;
}

#ifdef SPLIT_POINTING_ENABLE
// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 14.0//8.0 larger value make scroll slower
#define SCROLL_DIVISOR_V 14.0//8.0

// Enables support for extended mouse reports. (-32767 to 32767, instead of just -127 to 127)
#define MOUSE_EXTENDED_REPORT


// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        // mouse_report.h = -1 * mouse_report.x;
        // mouse_report.v = -1 * mouse_report.y;
        // mouse_report.x = 0;
        // mouse_report.y = 0;
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H * -1;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V * -1;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        scroll_accumulated_h = 0;
        scroll_accumulated_v = 0;
        if (precise_on == false) {
            mouse_report.x = (mouse_report.x> 0? mouse_report.x * mouse_report.x / 16 + mouse_report.x : -mouse_report.x * mouse_report.x / 16 + mouse_report.x);
            mouse_report.y = (mouse_report.y> 0? mouse_report.y * mouse_report.y / 16 + mouse_report.y : -mouse_report.y * mouse_report.y / 16 + mouse_report.y);
            // float magnitude = sqrtf(mouse_report.x * mouse_report.x + mouse_report.y * mouse_report.y);
            // float adjusted_magnitude = powf(magnitude, 0.3f);
            // mouse_report.x = (int16_t)(mouse_report.x * adjusted_magnitude);
            // mouse_report.y = (int16_t)(mouse_report.y * adjusted_magnitude);
        } else {
            mouse_report.x -= mouse_report.x / 8.0;
            mouse_report.y -= mouse_report.y / 8.0;
        }
    }
    return mouse_report;
}
#endif
