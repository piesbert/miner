/* Miner: glprogram.h
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

#if !defined(LOCK_MINER_GLPROGRAM_H)
#define LOCK_MINER_GLPROGRAM_H

#include "glshader.h"

#include <vector>

class GlProgram {
        public:
                GlProgram(const std::vector<GlShader> &);
                virtual ~GlProgram();

                GLuint getId() const;

                GLint getAttribId(const GLchar *) const;
                GLint getUniformId(const GLchar *) const;

        private:
                GLuint m_id;

                GlProgram(GlProgram const&); // do not implement
                GlProgram& operator=(GlProgram const&); // do not implement
}; // class GlProgram

#endif //LOCK_MINER_GLPROGRAM_H
