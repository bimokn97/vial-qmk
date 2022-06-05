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

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 11
#define MATRIX_ROW_PINS {B9, B8, B7, B6, B5, B4, B3, A15}
//#define MATRIX_COL_PINS {A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2 }
#define MATRIX_COL_PINS {NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }

#define UNUSED_PINS
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* disable it if your keyboard doesn't work on boot */
#define FORCE_NKRO

/* indicator leds */
#define LED_NUM_LOCK_PIN B10
#define LED_CAPS_LOCK_PIN B2

#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A6
#define SPI_MISO_PIN  A7

#define SN74X595_SPI_SLAVE_SELECT_PIN A3
#define SN74X595_SPI_CLOCK_DIVISOR 4
#define SN74X595_SPI_MODE 3
#define SN74X595_LENGTH 2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG
//#define DEBUG_MATRIX_SCAN_RATE

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
