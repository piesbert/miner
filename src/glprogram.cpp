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

#include <glm/gtc/type_ptr.hpp>

GLPROGRAM_CPP_SETTERS_2_ARGS(GLfloat,f)
GLPROGRAM_CPP_SETTERS_2_ARGS(GLdouble,d)

GLPROGRAM_CPP_SETTERS_3_ARGS(GLint,  i, I)
GLPROGRAM_CPP_SETTERS_3_ARGS(GLuint, ui, I)

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

bool GlProgram::inUse() const {
        GLint current = 0;

        glGetIntegerv(GL_CURRENT_PROGRAM, &current);
        return ((GLint)m_id == current);
}

void GlProgram::setUniformMatrix2(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix2fv(getUniformId(name), count, transpose, v);
}

void GlProgram::setUniformMatrix3(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix3fv(getUniformId(name), count, transpose, v);
}

void GlProgram::setUniformMatrix4(const GLchar* name, const GLfloat* v, GLsizei count, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix4fv(getUniformId(name), count, transpose, v);
}

void GlProgram::setUniform(const GLchar* name, const glm::mat2& m, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix2fv(getUniformId(name), 1, transpose, glm::value_ptr(m));
}

void GlProgram::setUniform(const GLchar* name, const glm::mat3& m, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix3fv(getUniformId(name), 1, transpose, glm::value_ptr(m));
}

void GlProgram::setUniform(const GLchar* name, const glm::mat4& m, GLboolean transpose) {
        assert(inUse());
        glUniformMatrix4fv(getUniformId(name), 1, transpose, glm::value_ptr(m));
}

void GlProgram::setUniform(const GLchar* uniformName, const glm::vec3& v) {
        setUniform3v(uniformName, glm::value_ptr(v));
}

void GlProgram::setUniform(const GLchar* uniformName, const glm::vec4& v) {
        setUniform4v(uniformName, glm::value_ptr(v));
}
