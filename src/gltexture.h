/* Miner: gltexture.h
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

#if !defined(LOCK_MINER_GLTEXTURE_H)
#define LOCK_MINER_GLTEXTURE_H

#include "build.h"

#include <GL/glew.h>
#include <string>

class GlTexture {
        public:
                GlTexture(const std::string &, const std::string &path = TEXTURES_PATH, GLint minMagFiler = GL_LINEAR, GLint wrapMode = GL_CLAMP_TO_EDGE);
                virtual ~GlTexture();

                GLuint getId() const;

                GLfloat width() const;
                GLfloat height() const;

        private:
                GLuint m_id;

                GLfloat m_width;
                GLfloat m_height;

                GlTexture(GlTexture const&); // do not implement
                GlTexture& operator=(GlTexture const&); // do not implement
}; // class GlTexture

#endif //LOCK_MINER_GLTEXTURE_H
