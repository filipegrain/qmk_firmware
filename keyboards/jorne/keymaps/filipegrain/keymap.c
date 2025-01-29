#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    RGBRST = SAFE_RANGE,
    SS_ITEM,
    SS_MASTER
};

// Modifier key definitions
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] =  LAYOUT(KC_LGUI, LT(3,KC_GRV), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(3,KC_LBRC), RALT_T(KC_RBRC), KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT), KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, LT(2,KC_TAB), RSFT_T(KC_SPC), LT(1,KC_ENT), LT(1,KC_ESC), LSFT_T(KC_BSPC), LT(2,KC_DEL)),

    [_LOWER] = LAYOUT(KC_TRNS, KC_UNDS, KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, KC_F1, KC_F2, KC_F3, KC_F9, KC_F10, KC_F11, RGUI_T(KC_F12), LCTL_T(KC_PPLS), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RCTL_T(KC_MINS), LALT_T(KC_EQL), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_RAISE] = LAYOUT(KC_TRNS, KC_CAPS, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_LCBR, KC_LBRC, SS_MASTER, SS_ITEM, KC_NO, KC_PSCR, KC_TRNS, LCTL_T(KC_PEQL), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, RCTL_T(KC_APP), KC_TRNS, KC_P0, KC_P1, KC_P2, KC_P3, KC_PCMM, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_ADJUST] = LAYOUT(KC_TRNS, KC_NO, KC_NO, KC_NO, MS_UP, MS_BTN2, MS_ACL2, MS_ACL2, MS_BTN3, MS_WHLU, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, MS_LEFT, MS_BTN1, MS_RGHT, MS_ACL1, MS_ACL1, MS_LEFT, MS_BTN1, MS_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MS_DOWN, KC_NO, MS_ACL0, MS_ACL0, KC_NO, MS_DOWN, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_ITEM:
            if (record->event.pressed) {
                SEND_STRING("505\n");
            }
            return false;

        case SS_MASTER:
            if (record->event.pressed) {
                SEND_STRING("0\t4547\n");
            }
            return false;

        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                }
            #endif
            return false;
    }
    return true;
}