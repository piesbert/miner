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

#include <GL/glut.h>

Config::Config() {
        m_glWidth  = 1024;
        m_glHeight = 768;
        m_glMode   = GLUT_DOUBLE | GLUT_RGBA;
}

Config::~Config() {
}

int Config::glWidth() const {
        return m_glWidth;
}

int Config::glHeight() const {
        return m_glHeight;
}

unsigned int Config::glMode() const {
        return m_glMode;
}
