#include QMK_KEYBOARD_H

#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _MOUSE   3

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

/* enum custom_keycodes {
    SHKEY = SAFE_RANGE,
    LSKEY,
    UPDIR,
    OYAMLLESS,
    LESS,
    KGALL
}; */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      #ifdef CONSOLE_ENABLE
      uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    switch (keycode) {
      case SHKEY:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("");
          } else {
              // when keycode QMKBEST is released
      }
      break;
      case LSKEY:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("ls -1\n");
          } else {
              // when keycode QMKBEST is released
      }
      break;
      case UPDIR:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("../\n");
          } else {
              // when keycode QMKBEST is released
      }
      break;
      case OYAMLLESS:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING("-oyaml | less\n");
          } else {
              // when keycode QMKBEST is released
      }
      break;
      case LESS:
          if (record->event.pressed) {
              // when keycode QMKBEST is pressed
              SEND_STRING(" | less\n");
          } else {
              // when keycode QMKBEST is released
      }
      break;
    }
    return true;
};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     _BASE
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                                     KC_LBRC, KC_RBRC, KC_PLUS,         KC_EQL, RAISE,   KC_SPC,
                                                              KC_ENT,  LOWER
    )
};
     */

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
      KC_TAB, KC_UNDS, KC_COMM, KC_DOT, KC_P, KC_Y,          KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
      KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I,                  KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT,
      ____, KC_COLN, KC_Q, KC_J, KC_K, KC_X,                 KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SPC,
                            MO(_NUMBERS), MO(_SYMBOLS), MO(_MOUSE),      KC_LGUI, KC_SPC, KC_LCTL,
                                   KC_LEFT_ALT, KC_LSFT
    ),
	[_SYMBOLS] = LAYOUT(
      KC_TAB, KC_QUES, KC_LT, KC_AT, KC_TILD, KC_CIRC,       KC_PERC, KC_AMPR, KC_EXLM, KC_PLUS, KC_BSLS, KC_BSPC,
      KC_ESC, KC_DQUO, KC_EQL, KC_LPRN, KC_RPRN, KC_ASTR,    KC_HASH, KC_QUOT, KC_SLSH, KC_MINS, KC_SCLN, KC_ENT,
      KC_GRAVE, KC_COLN, KC_LBRC, KC_LCBR, KC_DLR, UPDIR,       LSKEY, KC_PIPE, KC_RCBR, KC_RBRC, KC_GT, ____,
                                     ____, ____, ____,       KC_LGUI, KC_LALT, KC_LCTL,
                                           ____, ____
    ),
	[_NUMBERS] = LAYOUT(
      KC_TAB, KC_UNDS, KC_COMM, KC_DOT, KC_LSFT, ____,      ____, KC_INS, LESS, KC_MINS, OYAMLLESS, KC_BSPC,
      KC_ESC, KC_1, KC_2, KC_3, KC_4, SHKEY,                 KGALL, KC_7, KC_8, KC_9, KC_0, KC_ENT,
      ____, KC_COLN, KC_LEFT, KC_DOWN, KC_5, ____,         ____, KC_6,  KC_UP, KC_RGHT, KC_LSFT, ____,
                                   ____, ____, ____,            KC_LALT, KC_DOT, KC_NUM,
                                   ____, ____
    ),
	[_MOUSE] = LAYOUT(
      ____, DRG_TOG, SNP_TOG, KC_BTN3, ____, ____,      ____, ____, ____, ____, ____, ____,
      ____, DRGSCRL, SNIPING, KC_BTN2, KC_BTN1, ____,                 KC_UNDO, KC_COPY, KC_PASTE, KC_WWW_BACK, KC_WWW_FORWARD, KC_WWW_REFRESH,
      ____, DPI_RMOD, DPI_MOD, S_D_RMOD, S_D_MOD, ____,         ____, ____,  ____, ____, ____, ____,
                                   ____, ____, ____,            ____, ____, ____,
                                   ____, ____
    )
};
