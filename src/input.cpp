/* Miner: input.cpp
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

#include "input.h"
#include "actionmanager.h"

#include <SDL/SDL.h>

Input::Input() 
: m_actionManager(0) {
        m_actionManager = new ActionManager();
}

Input::~Input() {
        delete m_actionManager;
}

void Input::handle(const SDL_Event &ev) const {
}
