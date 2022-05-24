#pragma once

#define EE_HANDS
#define USE_SERIAL_PD2
#define TAPPING_TERM 172
#define TAPPING_TERM_PER_KEY
#define OLED_BRIGHTNESS 120
#define OLED_DISABLE_TIMEOUT

#if defined(SPLIT_KEYBOARD)
    #define SPLIT_WPM_ENABLE
    #define SPLIT_OLED_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE 
    #undef RGBLED_NUM
    #define RGBLED_NUM 8
    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT \
        {4, 4}              
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 5    
    #define RGBLIGHT_SAT_STEP 17    
    #define RGBLIGHT_VAL_STEP 17    
#endif

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
