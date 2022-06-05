/* Copyright (C) 2022
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "286_lt.h"
#include "print.h"
#include "debug.h"
#include "gpio.h"
#include "drivers/gpio/sn74x595.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    dprintf("col|row: %u|%u, kc: 0x%04X, pressed: %b, time: %u, interrupt: %b, count: %u\n", record->event.key.col, record->event.key.row, keycode, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
debug_sn74x595 = debug_matrix;
#endif

    if (record->event.pressed) {
        writePinLow(C13);
    } else {
        writePinHigh(C13);
    }

    return true;
}

void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable = false;
// debug_matrix     = false;
// debug_keyboard   = true;
// debug_mouse      = true;
    debug_sn74x595 = false;

    setPinOutput(C13);
    writePinLow(C13);
    sn74x595_init();
    keyboard_post_init_user();
}

void matrix_read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter) {
    // bool key_pressed = false;
    //  Select col
    sn74x595_setPinLow(current_col);

    // matrix_output_select_delay();

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Check row pin state
        if (readPin(row_pins[row_index]) == 0) {
            // Pin LO, set col bit
            current_matrix[row_index] |= row_shifter;
            // key_pressed = true;
        } else {
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~row_shifter;
        }
    }

    // chThdSleepSeconds(1);
    //  Unselect col
    // sn74x595_setPinHigh(current_col);
    sn74x595_AllPin_High();
    // matrix_output_unselect_delay(current_col, key_pressed); // wait for all Row signals to go HIGH
}
