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

enum {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_CUT,
    M_SELECT_ALL
};
char oled_layer[20];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        M_COPY, M_PASTE, KC_KP_9,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_UP, KC_KP_3,
        KC_LEFT,   KC_TRNS, KC_RIGHT
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [5] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [6] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [7] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
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
        }
    }
    return true;
}

// #ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_270;
// }

// bool oled_task_user(void) {
//   // Host Keyboard Layer Status
//     sprintf(oled_layer,"Layer\nL: %d\n",get_highest_layer(layer_state));
//     oled_write(oled_layer,false);

//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     oled_write_P(led_state.num_lock ? PSTR("NLCK ") : PSTR("     "), false);
//     oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("       "), false);
//     oled_write_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("       "), false);
//     return false;
// }
// #endif
