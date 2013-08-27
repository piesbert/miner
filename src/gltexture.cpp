/* Miner: gltexture.cpp
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

#include "gltexture.h"
#include "build.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

GlTexture::GlTexture(const std::string &name, const std::string &path, GLint minMagFiler, GLint wrapMode) {
        SDL_Surface *image;
        int mode;

        const char *file = std::string(path + name).c_str();

        image = IMG_Load(file);

        m_width  = image->w;
        m_height = image->h;

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFiler);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFiler);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

        mode = GL_RGB;

        if (4 == image->format->BytesPerPixel) {
                mode = GL_RGBA;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, mode, image->w, image->h, 0, mode, GL_UNSIGNED_BYTE, image->pixels);
}

GlTexture::~GlTexture() {
}

GLuint GlTexture::getId() const {
        return m_id;
}

GLfloat GlTexture::width() const {
        return m_width;
}

GLfloat GlTexture::height() const {
        return m_height;
}

