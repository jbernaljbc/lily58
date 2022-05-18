// kb: lily58
// km: neonlily

#include QMK_KEYBOARD_H
#include <stdio.h>

//extern uint8_t is_master;

enum corne_layers { // las capas en este keymap
    _QWERT,
    _LOWER,
    _RAISE,
    _TUNE
};

enum custom_keycodes { // dando nombre de keycodes por definir
    LOWER = SAFE_RANGE,
    RAISE,
    HUI,
    HUD,
};

/*
enum td_keycodes {
//    ESCAPE,
//    COMMAND,
//    ALT
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESCAPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DEL),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// hold es mantener la tecla presionada
// tap es "clickear" la tecla
// TD(ESCAPE) actua como ESCAPE con un tap y como DELETE con doble tap
// LSFT_T(KC_CAPS) actua como BLOQ MAYUS con tap y como SHIFT en hold
// LCTL_T(KC_QUOTE) actua como KC_QUOTE con tap (' o " si SHIFT esta presionado) y como CONTROL en hold
// SYMB en hold lleva a la capa _SYMB
// MT(NUMP,KC_ENT) actua como ENTER con tap y como NUMP en hold
// NUMP lleva a la capa _NUMP
// SYMB y NUMP en hold al mismo tiempo llevan a la capa _TUNE
// OS alterna entre _WIN10 y _MACOS para la capa base
// Tanto HUI como HUD son para cambiar el color de los LEDs en capa _MACOS
// HUI aumenta en 5 el valor Hue de color para capa base
// HUD disminuye en 5 el valor Hue de color para capa base
// KC_SLASH entrega simbolo � si ALTGR esta en hold
// KC_1 entrega simbolo � si ALTGR esta presionado
// ALTGR + n entrega la enhe
// ALTGR + vocal entrega vocal con tilde
// Este keymap debe usarse con el layout US International

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

//  [_QWERT] = LAYOUT(
//   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
//   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
//   KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
//                         KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_ENT, RAISE, KC_BSPC, KC_RGUI
// ),
 [_QWERT] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE),KC_RALT ,KC_RCTL 
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
// [_LOWER] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
//   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//   KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
//   _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//                              _______, _______, _______, _______, _______,  RAISE, _______, _______
// ),
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | PLAY  | STOP  | PREV  | NEXT  |  F5  |  F6  |-------.    ,-------|      | Left | Up | Down |Right |    |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  VUP  |  VDOWN |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

// [_RAISE] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
//   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//                              _______, _______, LOWER,  _______, _______,  _______, _______, _______
// ),
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_MPLY,KC_MSTP,KC_MPRV,KC_MNXT,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT, XXXXXXX,
  KC_VOLU, KC_VOLD, KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* TUNE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TOG |  HUI |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  HUD |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |      | /Space  /       \Enter \  |      |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_TUNE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG,   HUI,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,   HUD,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )

};

// ---------------------- variables -----------------------------

uint8_t mod_state;
bool key_registered;

uint32_t master_sleep;
uint32_t slave_sleep;

led_t led_usb_state;

uint8_t current_wpm = 0;
uint8_t current_hue;
uint8_t current_val;

// --------------------------------------------------------------

void keyboard_post_init_user(void) {
    current_hue = rgblight_get_hue();
    current_val = RGBLIGHT_LIMIT_VAL;
}    

layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    
        case _TUNE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_WHITE);
            }
            break;    
            
        case _RAISE:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(HSV_TEAL);
            }    
            break;            
            
        case _LOWER:
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(245, 255, current_val);
            }
            break;
                
        case _QWERT: 
            if (!host_keyboard_led_state().caps_lock) {
                rgblight_sethsv(current_hue, 255, current_val);
            }
            break;    
    }
    
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_sethsv(20, 255, current_val); // amarillo
    } else { 
        rgblight_sethsv(current_hue, 255, current_val);
    }
}

/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_CAPS):
        case MT(SYMB,KC_ENT):
        case MT(NUMP,KC_ENT):
        case LCTL_T(KC_QUOTE):
            return 125;
            
        default:
            return TAPPING_TERM;
    }
}
*/

#ifdef OLED_ENABLE // si OLED_ENABLE = yes en rules.mk

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
        master_sleep = timer_read32(); // se actualiza oled_sleep
    } 
}

static void render_layer(void) { // esta funcion muestra las capas en el OLED y resalta la capa presente
    oled_write_P(PSTR("RAISE"), layer_state_is(_RAISE) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("QWERT"), layer_state_is(_QWERT));
    oled_write_P(PSTR("LOWER"), layer_state_is(_LOWER) && !layer_state_is(_TUNE));
    oled_write_P(PSTR("TUNE\n"), layer_state_is(_TUNE));
}

static void slave_logo(void) {
    static const char PROGMEM lily58_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(lily58_logo, false);
    
    if (current_wpm != 0) { 
        slave_sleep = timer_read32(); // se actualiza oled_sleep
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
    // rotacion de 270 en OLED del master
    // rotacion de 180 en OLED del slave
    // de manera que el punto inicial este en un cierto extremo
    // y se siga cierta orientacion
}

bool oled_task_user(void) {
    
    current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (timer_elapsed32(master_sleep) > 60000 && timer_elapsed32(slave_sleep) > 60000 && current_wpm == 0) {
        if (is_oled_on()) {
            oled_off();
        }    
        timer_init();
        return false;
    }
    
    if (current_wpm != 0 && !is_oled_on()) {
        oled_on();
    }    
    
    if (is_keyboard_master()) { // OLED del master
        oled_set_cursor(0,1);
        master_logo();
        oled_set_cursor(0,5);
        render_layer(); // lo de las capas
        oled_set_cursor(0,10);
        render_mod();
    } else {
        slave_logo();
    } 

    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    switch (keycode) {
        
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            }
            return false;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _TUNE);
            }
            return false;


        case HUI:
            if (record->event.pressed) {
                current_hue = current_hue + 5;
                if (current_hue > 255) {
                    current_hue = current_hue - 256;
                }    
            } else {
                ;
            }
            return false;    
            
        case HUD:
            if (record->event.pressed) {
                current_hue = current_hue - 5;
                if (current_hue < 0) {
                    current_hue = 256 + current_hue;
                }    
            } else {
                ;
            }
            return false; 
    }
    return true;
}
