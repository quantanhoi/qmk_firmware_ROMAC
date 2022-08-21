/* Copyright 2018 Jack Humbert
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

#define _BASE 0
#define _FN1 1
enum {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_CUT,
    M_SELECT_ALL,
    M_UNDO,
    M_REDO
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		M_CUT, M_SELECT_ALL, KC_KP_9,
        KC_KP_4, KC_KP_5, KC_KP_6,
        M_COPY, KC_UP, M_PASTE,
        KC_LEFT,   KC_DOWN, KC_RIGHT
	),
  
	[_FN1] = LAYOUT(
		KC_TRNS, KC_HOME, KC_PGUP,
		KC_TRNS, KC_END, KC_PGDN,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_ENT
	)
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(record->event.pressed) {
        switch (keycode) {
            case M_COPY:
                SEND_STRING(SS_LCTL(SS_TAP(X_C)));
                return false;
                break;
            case M_PASTE:
                SEND_STRING(SS_LCTL(SS_TAP(X_V)));
                return false;
                break;
            case M_CUT:
            	SEND_STRING(SS_LCTL(SS_TAP(X_X)));
            	return false;
            	break;
        	case M_SELECT_ALL:
        		SEND_STRING(SS_LCTL(SS_TAP(X_A)));
            	return false;
            	break;
        	case M_UNDO:
            	SEND_STRING(SS_LCTL(SS_TAP(X_Z)));
            	return false;
            	break;
        	case M_REDO:
            	SEND_STRING(SS_LCTL(SS_TAP(X_Y)));
            	return false;
            	break;
        }
    }
    return true;
}