/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

//
// Calibration Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU

#include "menu_item.h"
#include "../../module/probe.h"
#include "../../feature/bedlevel/bedlevel.h"

void menu_calibration() {
    START_MENU();
    BACK_ITEM(MSG_MAIN);

    #if EITHER(HAS_BED_PROBE, PROBE_OFFSET_WIZARD)
    SUBMENU(MSG_PROBE_WIZARD, goto_probe_offset_wizard);
    #endif

    #if ENABLED(LEVEL_BED_CORNERS)
    SUBMENU(MSG_LEVEL_CORNERS, _lcd_level_bed_corners);
    #endif
    
    END_MENU();
}

#endif
