#include QMK_KEYBOARD_H

/*
Max Renner Preonic Layout need to finish and edit
Will add complete VIM functionality eventually
 */


//enum layers
enum preonic_layers {
  _QWERTY,
  _VIM,
  _FN,
  _LOWER,
  _RAISE
};

//enum keys
enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  VIM,
  LOWER,
  RAISE,
  FN
};

//define a few keys for VIM
#define WORDL LALT(KC_LEFT)
#define WORDR LALT(KC_RGHT)
#define EOL LGUI(KC_RIGHT)
#define BOL LGUI(KC_LEFT)
#define VIMESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+-------|
 * |EscCtl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right  |
 * `------------------------------------------------------------------------------------'
 */

	[_QWERTY] = LAYOUT_preonic_1x2uC( \
		KC_GRV,  		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,    \
		KC_TAB,  		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,     \
		VIMESC,	    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    \
		KC_LSFT, 		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,  \
		FN,   			KC_LCTL, KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT     \
		),

/* VIM
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      | WORDR|      |      |      |      |      |QWERTY|      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Left | Down |  Up  | Right|      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      | WORDL|      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |brite+|      |      |brite-|
 * ,------------------------------------------------------------------------------------.
 */

	[_VIM] = LAYOUT_preonic_1x2uC( \
		KC_NO,   KC_NO,	 KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
		KC_NO,   KC_NO,  WORDR,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   QWERTY,  KC_NO,   KC_NO,   KC_NO,   \
		KC_NO,   KC_NO,	 KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,   \
		KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,   WORDL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
		KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO    \
		),

/* fn
 * ,------------------------------------------------------------------------------------.
 * | vol+ |   f1 |  f2  |  f3  |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * | vol- |  f4  |  f5  |  f6  |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * | mute |  f7  |  f8  |  f9  |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |  f10 |  f11 |  f12 |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |brite+|      |      |brite-|
 * ,------------------------------------------------------------------------------------.
 */

	[_FN] = LAYOUT_preonic_1x2uC( \
		KC_VOLU,   KC_F1,   KC_F2,   KC_F3,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
		KC_VOLD,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
		KC_MUTE,   KC_F7,   KC_F8,   KC_F9,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
		KC_TRNS,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   \
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,        KC_TRNS,   KC_BRID,   KC_TRNS,   KC_TRNS,   KC_BRIU    \
		),

/* Lower
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |  1   |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \|  |
 * ,------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   (  |   )  |  - _ |   +  |  = + |   *  |   %  |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |   #  |   $  |   [{ |  ]}  |  _   |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

	[_LOWER] = LAYOUT_preonic_1x2uC( \
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
		KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,\
		VIM,     KC_EXLM, KC_AT  , KC_LPRN, KC_RPRN, KC_MINS, KC_PLUS, KC_EQL,  KC_ASTR, KC_PERC, KC_TRNS, KC_TRNS,  \
		KC_TRNS, KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS   \
		),

/* Raise (Still need to fill this out)
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | reset|
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |             |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

	[_RAISE] = LAYOUT_preonic_1x2uC( \
		RGB_TOG,   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    RESET,  \
		KC_TRNS,   RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  \
		KC_TRNS,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K,   RGB_M_X,   RGB_M_G,   RGB_M_T,   KC_TRNS,    KC_TRNS,  \
		BL_TOGG,   BL_STEP, BL_BRTG, BL_ON,   BL_INC,  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,  \
		KC_TRNS,   KC_TRNS, KC_TRNS, BL_OFF,  BL_DEC,      KC_TRNS,        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS   \
		)
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////                                                                                                                               ////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



float layer_change[][2] = SONG(QWERTY_SOUND);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

        case QWERTY:

			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
				currmode = INSERT_MODE;
				PLAY_SONG(layer_change);
			}
			return false;
			break;

        case VIM:

			if (record->event.pressed) {
				set_single_persistent_default_layer(_VIM);
				currmode = COMMAND_MODE;
				PLAY_SONG(layer_change);
			}
			return false;
			break;

	    case FN:
        	if (record->event.pressed) {
            	layer_on(_FN);
          	} else {
            	layer_off(_FN);
          	}
          	return false;
          	break;

		case LOWER:
          	if (record->event.pressed) {
            	layer_on(_LOWER);
          	} else {
            	layer_off(_LOWER);
          	}
          	return false;
          	break;

		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
			} else {
				layer_off(_RAISE);
			}
			return false;
			break;

		case V_o:
			if (record->event.pressed) {
				layer_on(_RAISE);
			}
			return false;
			break;
    }
    return true;
}
