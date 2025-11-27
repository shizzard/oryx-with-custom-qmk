#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

// Tap Dance definitions
enum {
  TD_LSFT_CAPS = 0,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};



#define KC_DFN0 LT(7, KC_F7)
#define KC_DFN1 LT(6, KC_F10)
#define KC_DFN2 LT(2, KC_T)
#define KC_DFN3 LT(15, KC_L)

// Custom keycode aliases
#define KC_AVLD KC_VOLD
#define KC_AVUP KC_VOLU
#define KC_BRDN KC_BRID
#define KC_BRUP KC_BRIU
#define KC_SPCE KC_SPACE
#define KC_ESCP KC_ESCAPE
#define KC_EQUL KC_EQUAL
#define KC_SLFT LGUI(KC_LEFT)
#define KC_SRGT LGUI(KC_RIGHT)
#define TD_SFCL TD(TD_LSFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_AVLD ,
                                                                        KC_AVUP ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_TRNS ,
    KC_ESCP ,KC_TRNS ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_BRDN ,
                                                                        KC_BRUP ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_TRNS ,KC_TRNS ,
    KC_TAB  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_HYPR ,
                                                                        KC_HYPR ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_P    ,KC_ENT  ,
    TD_SFCL ,KC_TRNS ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,
                                                                                 KC_N    ,KC_M    ,KC_Q    ,KC_Z    ,KC_TRNS ,KC_RSFT ,
    KC_LCTL ,KC_TRNS ,KC_TRNS ,KC_LALT ,KC_LGUI ,KC_TRNS ,
                                                                                 KC_TRNS ,KC_RGUI ,KC_RALT ,KC_TRNS ,KC_TRNS ,KC_RCTL ,
                                        KC_SPCE ,MO(1)  ,KC_TRNS  ,
                                                                        KC_TRNS ,MO(2)   ,KC_BSPC
  ),
  [1] = LAYOUT_moonlander(
    KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_TRNS ,
                                                                        KC_TRNS ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,
    KC_TRNS ,KC_TRNS ,KC_SCLN ,KC_QUES ,KC_EXLM ,KC_DQUO ,KC_TRNS ,
                                                                        KC_TRNS ,KC_TRNS ,KC_SLFT ,KC_DFN0 ,KC_SRGT ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_COLN ,KC_COMMA,KC_DOT  ,KC_EQUL ,KC_TRNS ,
                                                                        KC_TRNS ,KC_TRNS ,KC_DFN1 ,KC_DFN2 ,KC_DFN3 ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_SLASH,KC_MINUS,KC_ASTR ,KC_PLUS ,
                                                                                 KC_TRNS ,KC_PGUP ,KC_TRNS ,KC_PGUP ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_NO   ,
                                                                                 KC_NO   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                        KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                                                        KC_TRNS ,KC_TRNS ,KC_TRNS
  ),
  [2] = LAYOUT_moonlander(
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                                                        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_AT   ,KC_AMPR ,KC_LCBR ,KC_QUOTE,KC_TRNS ,
                                                                        KC_TRNS ,KC_GRAVE,KC_RCBR ,KC_PIPE ,CW_TOGG ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_HASH ,KC_TILD ,KC_LPRN ,KC_LBRC ,KC_TRNS ,
                                                                        KC_TRNS ,KC_RBRC ,KC_RPRN ,KC_UNDS ,KC_PERC ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_CIRC ,KC_LABK ,KC_BSLS ,
                                                                                 KC_SLASH,KC_RABK ,KC_DLR  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,RGB_MOD ,
                                                                                 QK_BOOT ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                        KC_TRNS ,KC_TRNS ,KC_TRNS ,
                                                                        KC_TRNS ,KC_TRNS ,KC_TRNS
  ),
};





void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_CROSS);  // Force cross mode
  rgb_matrix_sethsv_noeeprom(HSV_PURPLE);  // Set to purple with maximum brightness
  rgb_matrix_set_speed(200);  // Set animation speed (0-255, higher = faster)
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case KC_DFN0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_UP);
        } else {
          unregister_code16(KC_UP);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_UP);
        } else {
          unregister_code16(KC_UP);
        }  
      }  
      return false;
    case KC_DFN1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LEFT);
        } else {
          unregister_code16(KC_LEFT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT);
        } else {
          unregister_code16(KC_LEFT);
        }  
      }  
      return false;
    case KC_DFN2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DOWN);
        } else {
          unregister_code16(KC_DOWN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_DOWN);
        } else {
          unregister_code16(KC_DOWN);
        }  
      }  
      return false;
    case KC_DFN3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RIGHT);
        } else {
          unregister_code16(KC_RIGHT);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT);
        } else {
          unregister_code16(KC_RIGHT);
        }  
      }  
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

