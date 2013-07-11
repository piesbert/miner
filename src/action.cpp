/* Miner: action.cpp
 * Copyright (C) 2012-2013 Sebastian Szymak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "action.h"

#include <SDL/SDL.h>

Action::Action() {
}

Action::~Action() {
}

Action::State Action::isValid(const SDL_Event &ev) const {
        State retval = STATE_INVALID;

        if ((DEVICE_KEYBOARD == m_device) && (m_code == ev.key.keysym.sym)) {
                if (ev.type == SDL_KEYDOWN) {
                        retval = STATE_PRESSED;
                }
                else if (ev.type == SDL_KEYUP) {
                        retval = STATE_RELEASED;
                }
        }
        else if ((DEVICE_MOUSE == m_device) && (m_code == ev.button.button)) {
                if (ev.type == SDL_MOUSEBUTTONDOWN) {
                        retval = STATE_PRESSED;
                }
                else if (ev.type == SDL_MOUSEBUTTONUP) {
                        retval = STATE_RELEASED;
                }
        }

        return retval;
}

void Action::configure(DeviceId device, int code) {
        m_device = device;
        m_code   = code;
}
