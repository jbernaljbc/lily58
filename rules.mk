# rules.mk no esta en lenguaje C

# kb: lily58
# km: neonlily58

VIA_ENABLE = no

OLED_ENABLE = yes

OLED_DRIVER = SSD1306

RGBLIGHT_ENABLE = yes

MOUSEKEY_ENABLE = no

EXTRAKEY_ENABLE = yes
# EXTRAKEY_ENABLE es necesario para ocupar los keycodes KC_MUTE, KC_VOLD y KC_VOLU

TAP_DANCE_ENABLE = no
# necesario para ocupar el doble pulso (tap dance) en el keymap

WPM_ENABLE = yes
# necesario para ocupar get_current_wpm()
# obtener el valor de words per minute

LTO_ENABLE = yes
# Link Time Optimization reduce size al hex

EXTRAFLAGS += -flto
# esta linea reduce considerable size al hex

CONSOLE_ENABLE = no
