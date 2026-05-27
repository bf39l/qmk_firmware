// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <math.h>
#include <stdio.h>
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
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 TO(3),
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
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 TO(3),
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
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          TO(0),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO,

                 QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0),
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

#ifdef OLED_ENABLE
#ifndef OLED_TIMEOUT
#define OLED_TIMEOUT 30000
#endif

static const char PROGMEM sit[2][96] = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

static const char PROGMEM walk[2][96] = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

static const char PROGMEM run[2][96] = {
    {
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    {
        0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};

static uint8_t current_frame = 0;
static uint32_t anim_timer = 0;
static os_variant_t current_host_os = OS_UNSURE;

typedef enum {
    TOPLINE_MODE_HOST = 0,
    TOPLINE_MODE_WPM,
} topline_mode_t;

static topline_mode_t topline_mode = TOPLINE_MODE_HOST;

static const uint8_t glyph_3[5] = {0x21, 0x41, 0x45, 0x4B, 0x31};
static const uint8_t glyph_9[5] = {0x06, 0x49, 0x49, 0x29, 0x1E};
static const uint8_t glyph_A[5] = {0x7E, 0x11, 0x11, 0x11, 0x7E};
static const uint8_t glyph_B[5] = {0x7F, 0x49, 0x49, 0x49, 0x36};
static const uint8_t glyph_C[5] = {0x3E, 0x41, 0x41, 0x41, 0x22};
static const uint8_t glyph_F[5] = {0x7F, 0x09, 0x09, 0x09, 0x01};
static const uint8_t glyph_H[5] = {0x7F, 0x08, 0x08, 0x08, 0x7F};
static const uint8_t glyph_I[5] = {0x00, 0x41, 0x7F, 0x41, 0x00};
static const uint8_t glyph_K[5] = {0x7F, 0x08, 0x14, 0x22, 0x41};
static const uint8_t glyph_L[5] = {0x7F, 0x40, 0x40, 0x40, 0x40};
static const uint8_t glyph_M[5] = {0x7F, 0x02, 0x0C, 0x02, 0x7F};
static const uint8_t glyph_N[5] = {0x7F, 0x04, 0x08, 0x10, 0x7F};
static const uint8_t glyph_O[5] = {0x3E, 0x41, 0x41, 0x41, 0x3E};
static const uint8_t glyph_Q[5] = {0x3E, 0x41, 0x51, 0x21, 0x5E};
static const uint8_t glyph_R[5] = {0x7F, 0x09, 0x19, 0x29, 0x46};
static const uint8_t glyph_T[5] = {0x01, 0x01, 0x7F, 0x01, 0x01};
static const uint8_t glyph_U[5] = {0x3F, 0x40, 0x40, 0x40, 0x3F};
static const uint8_t glyph_W[5] = {0x7F, 0x20, 0x18, 0x20, 0x7F};
static const uint8_t glyph_b[5] = {0x7F, 0x48, 0x48, 0x48, 0x30};
static const uint8_t glyph_f[5] = {0x08, 0x7E, 0x09, 0x01, 0x02};
static const uint8_t glyph_a[5] = {0x20, 0x54, 0x54, 0x54, 0x78};
static const uint8_t glyph_blank[5] = {0x00, 0x00, 0x00, 0x00, 0x00};

static const uint8_t *glyph_5x7(char c) {
    switch (c) {
        case '3':
            return glyph_3;
        case '9':
            return glyph_9;
        case 'A':
            return glyph_A;
        case 'B':
            return glyph_B;
        case 'C':
            return glyph_C;
        case 'F':
            return glyph_F;
        case 'H':
            return glyph_H;
        case 'I':
            return glyph_I;
        case 'K':
            return glyph_K;
        case 'L':
            return glyph_L;
        case 'M':
            return glyph_M;
        case 'N':
            return glyph_N;
        case 'O':
            return glyph_O;
        case 'Q':
            return glyph_Q;
        case 'R':
            return glyph_R;
        case 'T':
            return glyph_T;
        case 'U':
            return glyph_U;
        case 'W':
            return glyph_W;
        case 'b':
            return glyph_b;
        case 'f':
            return glyph_f;
        case 'a':
            return glyph_a;
        default:
            return glyph_blank;
    }
}

static void draw_footer_text_line(uint8_t line, const char *text, bool invert) {
    uint8_t x = 0;
    uint8_t y = line * 8;

    if (invert) {
        for (uint8_t px = 0; px < 32; px++) {
            for (uint8_t py = y; py < y + 16 && py < 128; py++) {
                oled_write_pixel(px, py, true);
            }
        }
    }

    while (*text != '\0' && x < 32) {
        const uint8_t *glyph = glyph_5x7(*text);

        // Footer variant: slimmer than layer font (5 cols + 1 px spacing).
        for (uint8_t dcol = 0; dcol < 5 && x + dcol < 32; dcol++) {
            uint8_t bits = glyph[dcol];
            for (uint8_t row = 0; row < 7; row++) {
                if (bits & (1 << row)) {
                    uint8_t py = y + (row * 2);
                    if (py < 128) {
                        oled_write_pixel(x + dcol, py, !invert);
                    }
                    if (py + 1 < 128) {
                        oled_write_pixel(x + dcol, py + 1, !invert);
                    }
                }
            }
        }

        x += 6;
        text++;
    }
}

static void draw_big_text_line(uint8_t line, const char *text, bool invert) {
    uint8_t x = 0;
    uint8_t y = line * 8;

    if (invert) {
        // Fill two text rows (16 px) with white, then draw glyph strokes in black.
        for (uint8_t px = 0; px < 32; px++) {
            for (uint8_t py = y; py < y + 16 && py < 128; py++) {
                oled_write_pixel(px, py, true);
            }
        }
    }

    while (*text != '\0' && x < 32) {
        const uint8_t *glyph = glyph_5x7(*text);

        // Stretch 5 source columns to 7 destination columns and keep 1 blank column as spacing.
        for (uint8_t dcol = 0; dcol < 7 && x + dcol < 32; dcol++) {
            uint8_t scol = (dcol * 5) / 7;
            uint8_t bits = glyph[scol];
            for (uint8_t row = 0; row < 7; row++) {
                if (bits & (1 << row)) {
                    uint8_t py = y + (row * 2);
                    if (py < 128) {
                        oled_write_pixel(x + dcol, py, !invert);
                    }
                    if (py + 1 < 128) {
                        oled_write_pixel(x + dcol, py + 1, !invert);
                    }
                }
            }
        }

        x += 8;
        text++;
    }
}

static void render_slave_status(void) {
    oled_clear();
}

static const char *host_os_label(void) {
    switch (current_host_os) {
        case OS_MACOS:
        case OS_IOS:
            return "MAC";
        case OS_WINDOWS:
            return "WIN";
        case OS_LINUX:
            return "LIN";
        default:
            return "UNKN";
    }
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    current_host_os = detected_os;
    return true;
}

static const char *layer_label(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            return "QWRT";
        case 1:
            return "CLMK";
        case 2:
            return "FUNC";
        case 3:
            return "CONF";
        default:
            return "OTHR";
    }
}

static void render_mask_lines(uint8_t mods, uint8_t base_line) {
    char line[5] = {'.', '.', '.', '.', '\0'};

    oled_set_cursor(0, base_line);
    oled_write_P(PSTR("Masks"), false);

    if (mods & MOD_MASK_SHIFT) {
        line[0] = 'S';
    }
    if (mods & MOD_MASK_CTRL) {
        line[1] = 'C';
    }
    if (mods & MOD_MASK_ALT) {
        line[2] = 'A';
    }
    if (mods & MOD_MASK_GUI) {
        line[3] = 'G';
    }

    oled_set_cursor(0, base_line + 1);
    oled_write(line, false);
}

static void render_lock_lines(led_t led_state, uint8_t base_line) {
    char line[17];

    oled_set_cursor(0, base_line);
    oled_write_P(PSTR("Locks"), false);
    snprintf(line, sizeof(line), "%c%c%c",
             led_state.caps_lock ? 'C' : '.',
             led_state.num_lock ? 'N' : '.',
             led_state.scroll_lock ? 'S' : '.');
    oled_set_cursor(0, base_line + 1);
    oled_write(line, false);
}

static void render_host_os_line(void) {
    oled_write(host_os_label(), false);
}

static void render_wpm_line(void) {
    char line[17];

#ifdef WPM_ENABLE
    snprintf(line, sizeof(line), "W:%3u", get_current_wpm());
    oled_write(line, false);
#else
    oled_write_P(PSTR("W:OFF"), false);
#endif
}

void set_oled_topline_mode(const char *mode) {
    if (mode == NULL) {
        return;
    }

    if (strcmp(mode, "wpm") == 0) {
        topline_mode = TOPLINE_MODE_WPM;
    } else if (strcmp(mode, "host") == 0) {
        topline_mode = TOPLINE_MODE_HOST;
    }
}

static void render_topline(void) {
    if (topline_mode == TOPLINE_MODE_WPM) {
        render_wpm_line();
    } else {
        render_host_os_line();
    }
}

static void render_master_cat(void) {
    int current_wpm = get_current_wpm();
    uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);
    // Tuned around ~60 WPM average typing: walk state with medium frame pace.
    int16_t frame_delay = 360 - (current_wpm * 3);
    const uint8_t cat_line = 1;
    const uint8_t wpm_line = 4;
    const uint8_t layer_line = 5;
    const uint8_t mask_line = 8;
    const uint8_t lcks_line = 11;
    const uint8_t footer_line = 14;

    if (frame_delay < 110) {
        frame_delay = 110;
    }
    if (frame_delay > 320) {
        frame_delay = 320;
    }

    if (timer_elapsed32(anim_timer) > (uint32_t)frame_delay) {
        anim_timer = timer_read32();
        current_frame ^= 1;
    }

    if (active_layer == 3) {
        set_oled_topline_mode("wpm");
    } else {
        set_oled_topline_mode("host");
    }

    oled_clear();
    oled_set_cursor(0, cat_line);

    if (current_wpm < 20) {
        oled_write_raw_P(sit[current_frame], sizeof(sit[0]));
    } else if (current_wpm <= 40) {
        oled_write_raw_P(walk[current_frame], sizeof(walk[0]));
    } else {
        oled_write_raw_P(run[current_frame], sizeof(run[0]));
    }

    oled_set_cursor(0, wpm_line);
    render_topline();

    draw_big_text_line(layer_line, layer_label(), false);

    render_mask_lines(get_mods() | get_oneshot_mods(), mask_line);

    render_lock_lines(host_keyboard_led_state(), lcks_line);

    draw_footer_text_line(footer_line, "bf39L", false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// bool oled_task_user(void) {
//     render_logo();
//     return false;
// }

bool oled_task_user(void) {
    if (last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return false;
    }

    oled_on();

    if (!is_keyboard_master()) {
        render_slave_status();
        return false;
    }

    render_master_cat();
    return false;
}
#endif
