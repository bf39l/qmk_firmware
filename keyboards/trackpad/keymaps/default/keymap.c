// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
        KC_A
    )
};


// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 15.0//8.0 larger value make scroll slower
#define SCROLL_DIVISOR_V 15.0//8.0
// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.h != 0) {
        scroll_accumulated_h += (float)mouse_report.h / SCROLL_DIVISOR_H * -1;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    }
    if (mouse_report.v != 0) {
        scroll_accumulated_v += (float)mouse_report.v / SCROLL_DIVISOR_V * -1;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;
    }
    return mouse_report;
}
