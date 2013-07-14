/* Miner: glshader.h
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

#if !defined(LOCK_MINER_GLSHADER_H)
#define LOCK_MINER_GLSHADER_H

#include <GL/glew.h>
#include <string>

class GlShader {
        public:
                GlShader(const std::string &, GLenum);
                virtual ~GlShader();

                GLuint getId() const;

                static GlShader fromFile(const std::string &, GLenum);

                GlShader(GlShader const&);
                GlShader& operator=(GlShader const&);
        private:
                GLuint        m_id;
                unsigned int *m_refCount;

                void keep();
                void release();
}; // class GlShader

#endif //LOCK_MINER_GLSHADER_H
