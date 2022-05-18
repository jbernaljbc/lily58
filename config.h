// kb: lily58
// km: neonlily58

#pragma once

// #define USE_MATRIX_I2C

#define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD

#define TAPPING_TERM 200
// el doble pulso del Tap Dance debe hacerse en menos de 400ms. Tambien es el tiempo que diferencia el tap del hold

// #define TAPPING_TERM_PER_KEY

#define OLED_BRIGHTNESS 120

#define OLED_DISABLE_TIMEOUT

#if defined(SPLIT_KEYBOARD)
    #define SPLIT_WPM_ENABLE
    #define SPLIT_OLED_ENABLE
#endif

//#define RGBW

#ifdef RGBLIGHT_ENABLE // si la linea RGBLIGHT_ENABLE = yes esta en rules.mk

    #undef RGBLED_NUM
       
    #define RGBLED_NUM 8// numero de LEDs en el teclado
    
    #undef RGBLED_SPLIT
    
    #define RGBLED_SPLIT \
        {4, 4}
       
    // #define RGBLIGHT_EFFECT_BREATHING
    // incluyendo el efecto RGB breathing
    
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // incluyendo el efecto RGB rainbow mood
    
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
               
    #define RGBLIGHT_LIMIT_VAL 120
    // maximo valor para Value en HSV
    
    #define RGBLIGHT_HUE_STEP 5
    // valor del step al modificar Hue
    
    #define RGBLIGHT_SAT_STEP 17
    // valor del step al modificar Saturation
    
    #define RGBLIGHT_VAL_STEP 17
    // valor del step al modificar Value
    
#endif

#define NO_ACTION_MACRO 
// ya que tengo EXTRAFLAGS += -flto en rules.mk

#define NO_ACTION_FUNCTION 
// ya que tengo EXTRAFLAGS += -flto en rules.mk
