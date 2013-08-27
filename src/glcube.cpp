/* Miner: glcube.cpp
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

#include "glcube.h"
#include "gltexture.h"

GlCube::GlCube() {
        for (int i = 0; i < SIDE_MAX; i++) {
                m_textures[i] = 0;
        }
}

GlCube::~GlCube() {
        for (int i = 0; i < SIDE_MAX; i++) {
                delete m_textures[i];
        }
}

void GlCube::setTexture(const std::string &name, Side side) {
        if (SIDE_MAX == side) {
        }
        else {
                if (0 != m_textures[side]) {
                        delete m_textures[side];
                }

                m_textures[side] = new GlTexture(name);
        }
}
