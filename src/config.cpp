/* Miner: config.cpp
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

#include "config.h"

#include <SDL/SDL.h>

Config::Config() {
        m_glWidth  = 1024;
        m_glHeight = 768;
        m_glMode   = SDL_OPENGL | SDL_RESIZABLE;
        m_glFov    = 90;
}

Config::~Config() {
}

int Config::glWidth() const {
        return m_glWidth;
}

void Config::set_glWidth(int width) {
        m_glWidth = width;
}

int Config::glHeight() const {
        return m_glHeight;
}

void Config::set_glHeight(int height) {
        m_glHeight = height;
}

unsigned int Config::glMode() const {
        return m_glMode;
}

unsigned int Config::glFov() const {
        return m_glFov;
}
