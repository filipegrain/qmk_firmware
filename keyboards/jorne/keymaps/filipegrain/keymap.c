// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(KC_LGUI, KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, RALT_T(KC_RBRC), KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT), KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, LT(2,KC_TAB), RSFT_T(KC_SPC), LT(1,KC_ESC), LT(1,KC_ENT), LSFT_T(KC_BSPC), LT(2,KC_DEL)),

[_LOWER] = LAYOUT(KC_TRNS, KC_UNDS, MS_BTN3, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, MS_BTN1, MS_BTN2, RGUI_T(KC_F12), LCTL_T(KC_PPLS), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RCTL_T(KC_MINS), LALT_T(KC_EQL), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_RAISE] = LAYOUT(KC_TRNS, KC_NUM, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MSTP, KC_TRNS, LCTL_T(KC_PEQL), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_CAPS, RCTL_T(KC_APP), KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_PCMM, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_ADJUST] = LAYOUT(QK_BOOT, KC_NO, AS_UP, AS_TOGG, AS_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AS_DOWN, AS_TOGG, AS_UP, KC_NO, QK_BOOT, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UG_VALU, UG_SATU, UG_HUEU, UG_TOGG, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UG_VALD, UG_SATD, UG_HUED, UG_NEXT, KC_TRNS, SH_TOGG, KC_TRNS, KC_TRNS, SH_TOGG, KC_TRNS)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

