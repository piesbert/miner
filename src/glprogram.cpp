/* Miner: glprogram.cpp
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

#include "glprogram.h"
#include "log.h"

GlProgram::GlProgram(const std::vector<GlShader> &shaders) :
m_id(0) {
        GLint status;
        GLint length;
        char *info;

        if (shaders.size() <= 0) {
                LOGERR("No shaders provided");
        }

        m_id = glCreateProgram();

        if (0 == m_id) {
                LOGERR("Program creation failed");
        }

        for (unsigned int i = 0; i < shaders.size(); i++) {
                glAttachShader(m_id, shaders[i].getId());
        }

        glLinkProgram(m_id);

        for (unsigned int i = 0; i < shaders.size(); i++) {
                glDetachShader(m_id, shaders[i].getId());
        }

        glGetProgramiv(m_id, GL_LINK_STATUS, &status);

        if (GL_FALSE == status) {
                glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &length);
                info = new char[length + 1];
                glGetProgramInfoLog(m_id, length, 0, info);
                LOGERR("Program linking failed: " << info);
                delete[] info;

                glDeleteProgram(m_id);
                m_id = 0;
        }
}

GlProgram::~GlProgram() {
        if (0 != m_id) {
                glDeleteProgram(m_id);
        }
}

GLuint GlProgram::getId() const {
        return m_id;
}

GLint GlProgram::getAttribId(const GLchar *name) const {
        GLint retval = -1;

        if (0 == name) {
                LOGWRN("Attribute name empty!");
        }
        else {
                retval = glGetAttribLocation(m_id, name);
                if (-1 == retval) {
                        LOGWRN("Attribute not found: " << name);
                }
        }       
 
        return retval;
}

GLint GlProgram::getUniformId(const GLchar *name) const {
        GLint retval = -1;

        if (0 == name) {
                LOGWRN("Uniform name empty!");
        }
        else {
                retval = glGetUniformLocation(m_id, name);
                if (-1 == retval) {
                        LOGWRN("Uniform not found: " << name);
                }
        }

        return retval;
}
