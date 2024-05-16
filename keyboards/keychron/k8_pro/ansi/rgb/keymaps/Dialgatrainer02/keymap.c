/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/mouse_turbo_click.h"
#include "features/sentence_case.h"
#include "features/email.h"

// clang-format off
enum layers{
  LNX_BASE,
  LNX_FN,
  LNX_MO,
  GAME,
};

enum custom_keycodes {
  BRACES = NEW_SAFE_RANGE,
  DBLCLK,
  TURBO,
  TURBO_UP,
  TURBO_DN,
  USRNAME,
  EMAIL,
  LOCK,
  BASE,
  DM_END,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LNX_BASE] = LAYOUT_tkl_ansi(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_NO,     LOCK,     RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  TG(GAME),
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BRACES,   BRACES,   KC_BSLS,  KC_DEL,    DM_END,   TT(LNX_MO),
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(LNX_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[LNX_FN] = LAYOUT_tkl_ansi(
     KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,             KC_WH_U,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_WH_L,  KC_WH_D,   KC_WH_R),

[LNX_MO] = LAYOUT_tkl_ansi(
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  BASE,     KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     EE_CLR,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_BTN1,
     AS_TOGG,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_BTN2,            KC_MS_U,
     AC_TOGG,  EMAIL,    USRNAME,                                KC_TRNS,                                QK_REP,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,   KC_MS_R),
[GAME] = LAYOUT_tkl_ansi(
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TURBO_DN,  TURBO,  TURBO_UP,  KC_TRNS,  KC_TRNS,  KC_TRNS,            DBLCLK,   BASE,     KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_REC1,  KC_TRNS,  DM_REC2,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_PLY1,  KC_TRNS,  DM_PLY2,
     QK_LOCK,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,           KC_TRNS,
     KC_LCTL, KC_TRNS, KC_LALT,                        KC_TRNS,                                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS),

};
bool recording = false;//varibles for dyn macro recording and direction
int8_t macro  = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }
  if (!process_sentence_case(keycode, record)) { return false; }

  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
    case DBLCLK:  // Double click the left mouse button.
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(50) SS_TAP(X_BTN1));
    }
    return false;
    case TURBO_UP:  // increase turbo speed
    if (record->event.pressed) {
      //click speed up means period is lower
      extern int MOUSE_TURBO_CLICK_PERIOD; // bring in the varible from ther header
      MOUSE_TURBO_CLICK_PERIOD -= 5;//mOuse turbo click period is defined in  mouse_turbo_click.c which isnt sourced however the header is
      if (MOUSE_TURBO_CLICK_PERIOD <= 15) {
          MOUSE_TURBO_CLICK_PERIOD = 20;
      }
    }
    return false;
    case TURBO_DN:  // decrease turbo speed
    if (record->event.pressed) {
      //click speed down means period is higher
      extern int MOUSE_TURBO_CLICK_PERIOD; // bring in the varible from the header
      MOUSE_TURBO_CLICK_PERIOD += 5;
    }
    return false;

    case BRACES:  // Types [], {}, or <> and puts cursor between braces.
      if (record->event.pressed) {
        clear_oneshot_mods();  // Temporarily disable mods.
        unregister_mods(MOD_MASK_CSAG);
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("{}");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("<>");
        } else {
          SEND_STRING("[]");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        register_mods(mods);  // Restore mods.
    }
    return false;
    case USRNAME:  // send my username
      if (record->event.pressed) {
        send_string("Dialgatrainer069"SS_TAP(X_ENTER));
    }
    return false;

    case LOCK:  // super l combo
    if (record->event.pressed) {
      clear_oneshot_mods();  // Temporarily disable mods.
      unregister_mods(MOD_MASK_CSAG);
      SEND_STRING(SS_LGUI("l"));
      register_mods(mods);
    }
    return false;
    case EMAIL:
    if (record->event.pressed) {
        if (strcmp(GMAIL,"invalid@example") == 1 ) {
            SEND_STRING(GMAIL);
        }
    }
    return false;
    case BASE:
    if (record->event.pressed) {
      layer_move(LNX_BASE);
    }
    return false;
    case DM_END:
    if (record->event.pressed) {
      if (recording == true) {
        dynamic_macro_stop_recording();
      }
      else {
        tap_code(KC_END);
      }
    }
    return false;
  }
  return true;
}

/*
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if(active) { layer_on(GAME); } else { layer_off(GAME); }
            break;
    }
    return true;
}
*/

//make bound keys on a higher layer orange
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_ORANGE);
                }
            }
        }
    }//make mods go red when locked or otherwise held
  const uint8_t mods = get_mods();
  if (mods & MOD_BIT_LCTRL) {
    rgb_matrix_set_color(76, RGB_RED);
  }
  if (mods & MOD_BIT_LSHIFT) {
    rgb_matrix_set_color(63, RGB_RED);
  }
  if (mods & MOD_BIT_LALT) {
    rgb_matrix_set_color(78, RGB_RED);//right and left are difrent and even though the signal is the same i wanted astectics when locking the key
  }
  if (mods & MOD_BIT_RCTRL) {
    rgb_matrix_set_color(83, RGB_RED);
  }
  if (mods & MOD_BIT_RSHIFT) {
    rgb_matrix_set_color(74, RGB_RED);
  }
  if (mods & MOD_BIT_RALT) {
    rgb_matrix_set_color(80, RGB_RED);
  }
  if (recording == true && macro == 1) {
    rgb_matrix_set_color(48, RGB_RED);
    rgb_matrix_set_color(47, RGB_RED);
    rgb_matrix_set_color(30, RGB_RED);
  }
  if (recording == true && macro == -1) {
    rgb_matrix_set_color(48, RGB_RED);
    rgb_matrix_set_color(49, RGB_RED);
    rgb_matrix_set_color(32, RGB_RED);
  }
  if (IS_LAYER_ON(GAME)) {
    rgb_matrix_set_color(35, RGB_GREEN);//w
    rgb_matrix_set_color(52, RGB_GREEN);//s
    rgb_matrix_set_color(51, RGB_GREEN);//a
    rgb_matrix_set_color(53, RGB_GREEN);//d
  }
  return false;
}

void dynamic_macro_record_start_user(int8_t direction) {
    recording = true;
    macro = direction;//todo fix shift issue when recording and playing back dynamic macros`
    unregister_mods(MOD_MASK_SHIFT);
}

void dynamic_macro_record_end_user(int8_t direction){
    recording = false;
    macro = 0;
}


// disable things that could interfrer with the game
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case GAME:
        //disable things
        autocorrect_disable();
        autoshift_disable();
        break;
    default:
       autocorrect_enable();//reset from game layer
       autoshift_enable();
       clear_oneshot_mods();//clear mods
       clear_mods();
       cancel_key_lock();
       break;
    }
  return state;
}
