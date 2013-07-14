/* Miner: glshader.cpp
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

#include "glshader.h"
#include "log.h"

#include <fstream>
#include <sstream>

GlShader::GlShader(const std::string &code, GLenum type) :
m_id(0),
m_refCount(0) {
        const char* source = code.c_str();

        GLint status;
        GLint length;

        char* info;

        m_id =glCreateShader(type);

        if (0 == m_id) {
                LOGERR("Failed to create shader.");
        }

        glShaderSource(m_id, 1, (const GLchar **)&source, 0);
        glCompileShader(m_id);
        glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);

        if (GL_FALSE == status) {
                glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &length);

                info = new char[length + 1];
                glGetShaderInfoLog(m_id, length, 0, info);
                
                LOGERR("Shader compilation failed:" << std::endl << info);
                delete [] info;

                glDeleteShader(m_id);
                m_id = 0;
        }

}

GlShader::GlShader(const GlShader& shader) :
m_id(shader.m_id),
m_refCount(shader.m_refCount) {
        keep();
}

GlShader& GlShader::operator=(const GlShader& shader) {
        release();

        m_id = shader.m_id;
        m_refCount = shader.m_refCount;

        keep();

        return *this;
}

GlShader::~GlShader() {
        if (0 != m_refCount) {
                release();
        }
}

GLuint GlShader::getId() const {
        return m_id;
}

GlShader GlShader::fromFile(const std::string &path, GLenum type) {
        std::ifstream     fileStream;
        std::stringstream stringStream;

        fileStream.open(path.c_str(), std::ios::in | std::ios::binary);

        if (!fileStream.is_open()) {
                LOGERR("Failed to open file: " << path);
        }
        
        stringStream << fileStream.rdbuf();

        return GlShader(stringStream.str(), type);
}

void GlShader::keep() {
        *m_refCount += 1;
}

void GlShader::release() {
        *m_refCount -= 1;

        if (0 == *m_refCount) {
                glDeleteShader(m_id);
                m_id = 0;

                delete m_refCount;
                m_refCount = 0;
        }
}
