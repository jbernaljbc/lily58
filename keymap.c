#include QMK_KEYBOARD_H
#include <stdio.h>

enum corne_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _TUNE
};

enum custom_keycodes {
    CK_LOWER = SAFE_RANGE,
    CK_RAISE
};

enum td_keycodes {
    TAB,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  =  |          
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RALT | RCTL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    TD(TAB),  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                          KC_LALT, KC_LGUI, CK_LOWER, KC_SPC,       KC_ENT,  CK_RAISE ,KC_RALT ,KC_RCTL 
),

 /* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |       |      |     |       |      |     |                    |  F10  | F11  | F12 |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  \   |   |  |  `   |                    |  F7  |  F8  |  F9  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  PUP | HOME |-------.    ,-------|  F4  |  F5  |  F6  |      |      |      |
 * |------+------+------+------+------+------| VDOWN |    |  VUP  |------+------+------+------+------+------|
 * |      |      |      | DEL  | PDWN | END  |-------|    |-------|  F1  |  F2  |  F3  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */ 
 [_LOWER] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_BSLS, KC_PIPE, KC_GRV,                    KC_F7,   KC_F8,   KC_F9,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,                   KC_F4,   KC_F5,   KC_F6,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_DEL,  KC_PGDN, KC_END, KC_VOLD, KC_VOLU,  KC_F1,   KC_F2,   KC_F3,  XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______, _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                        ,-----------------------------------------.
 * |      |      |      |      |      |      |                        |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                        |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.        ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|  PLAY |       |  STOP  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|       |--------|      |      |      |      |      |      |
 * `-----------------------------------------/       /       \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /         \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /           \      \ |      |      |      |
 *                   `----------------------------'            '------''--------------------'
 */
 [_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,  KC_UP , XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MPLY, KC_MSTP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

 /* TUNE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | TOG  |  HUI |  HUD |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | SAI  |  SAD | VAI  | VAD  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |      | /Space  /       \Enter \  |      |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_TUNE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

uint32_t master_sleep;
uint32_t slave_sleep;

led_t led_usb_state;

uint8_t current_wpm = 0;
uint8_t current_hue;
uint8_t current_val;

void keyboard_post_init_user(void) {
    current_hue = rgblight_get_hue();
    current_val = RGBLIGHT_LIMIT_VAL;
}    

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _TUNE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_RED);
            }
            break;    
            
        case _RAISE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_GREEN);
            }    
            break;            
            
        case _LOWER:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(245, 255, current_val);
            }
            break;
        case _QWERTY: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_TEAL);
            }
            break;    
    }
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(20, 255, current_val);
    } else {
        rgblight_sethsv(HSV_TEAL);
    }
}

#ifdef OLED_ENABLE

static void master_logo(void) {
    static const char PROGMEM lily_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x30, 
        0x18, 0x30, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x20, 0xf0, 0x20, 0x20, 0x60, 0xf0, 0x60, 0x20, 0xf0, 
        0x00, 0x00, 0x00, 0x1f, 0x79, 0xc1, 0x03, 0x02, 0x02, 0x06, 0x06, 0x04, 0x0f, 0x19, 0x30, 0x60, 
        0xc0, 0x80, 0x00, 0x01, 0x3f, 0xfc, 0x20, 0x72, 0xff, 0x77, 0x22, 0x30, 0x78, 0x30, 0x22, 0x7f, 
        0x70, 0xdc, 0xc6, 0x82, 0x83, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x82, 0x82, 0xc4, 
        0x70, 0xd9, 0x98, 0x8c, 0x02, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x82, 0x86, 0xec, 0x38, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(lily_logo, 128);
    
    if (current_wpm != 0) { 
        master_sleep = timer_read32();
    } 
}

static void render_layer(void) {
    oled_write_P(PSTR("QWERT"), layer_state_is(_QWERTY));   
    oled_write_P(PSTR("LOWER"), layer_state_is(_LOWER) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("RAISE"), layer_state_is(_RAISE) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("TUNE\n\n"), layer_state_is(_TUNE));
}

static void slave_logo(void) {
    static const char PROGMEM lily58_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(lily58_logo, false);
    
    if (current_wpm != 0) { 
        slave_sleep = timer_read32();
    } 
}

static void render_mod(void) {
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
    oled_write_P(PSTR("SHIFT"), (keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)));
    oled_write_ln_P(PSTR("CTRL"), (keyboard_report->mods & MOD_BIT (KC_LCTRL)) || (keyboard_report->mods & MOD_BIT (KC_RCTRL)));
    oled_write_P(PSTR("ALTGR"), keyboard_report->mods & MOD_BIT (KC_RALT));
    oled_write_ln_P(PSTR("ALT"),  keyboard_report->mods & MOD_BIT (KC_LALT));
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    
    current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (timer_elapsed32(master_sleep) > 120000 && timer_elapsed32(slave_sleep) > 120000 && current_wpm == 0) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return false;
    }
    
    if (current_wpm != 0 && !is_oled_on()) {
        oled_on();
    }    
    
    if (is_keyboard_master()) {
        oled_set_cursor(0,1);
        master_logo();
        oled_set_cursor(0,5);
        render_layer();
        oled_set_cursor(0,10);
        render_mod();
    } else {
        slave_logo();
    } 

    return false;
}
#endif 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            }
            return false;
        
        case CK_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            }
            return false;
    }
    return true;
}
