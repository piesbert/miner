/* Miner: glcube.h
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

#if !defined(LOCK_MINER_GLCUBE_H)
#define LOCK_MINER_GLCUBE_H

#include <string>

class GlTexture;

class GlCube {
        public:
                enum Side {
                        SIDE_TOP = 0,
                        SIDE_BOTTOM,
                        SIDE_LEFT,
                        SIDE_RIGHT,
                        SIDE_FRONT,
                        SIDE_BACK,
                        SIDE_MAX
                };

                GlCube();
                virtual ~GlCube();

                void setTexture(const std::string &name, Side side = SIDE_MAX); 

        private:
                int m_x;
                int m_y;
                int m_z;

                GlTexture *m_textures[SIDE_MAX];

                GlCube(GlCube const&); // do not implement
                GlCube& operator=(GlCube const&); // do not implement
}; // class GlCube

#endif //LOCK_MINER_GLCUBE_H
