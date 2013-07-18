/* Miner: gldefine.h
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

#if !defined(LOCK_MINER_GLDEFINE_H)
#define LOCK_MINER_GLDEFINE_H

#define GLPROGRAM_HEADER_SETTERS(OGL_TYPE) \
void setAttrib(const GLchar *, OGL_TYPE); \
void setAttrib(const GLchar *, OGL_TYPE, OGL_TYPE); \
void setAttrib(const GLchar *, OGL_TYPE, OGL_TYPE, OGL_TYPE); \
void setAttrib(const GLchar *, OGL_TYPE, OGL_TYPE, OGL_TYPE, OGL_TYPE); \
void setAttrib1v(const GLchar *, const OGL_TYPE *); \
void setAttrib2v(const GLchar *, const OGL_TYPE *); \
void setAttrib3v(const GLchar *, const OGL_TYPE *); \
void setAttrib4v(const GLchar *, const OGL_TYPE *); \
void setUniform(const GLchar *, OGL_TYPE); \
void setUniform(const GLchar *, OGL_TYPE, OGL_TYPE); \
void setUniform(const GLchar *, OGL_TYPE, OGL_TYPE, OGL_TYPE); \
void setUniform(const GLchar *, OGL_TYPE, OGL_TYPE, OGL_TYPE, OGL_TYPE); \
void setUniform1v(const GLchar *, const OGL_TYPE *, GLsizei count = 1); \
void setUniform2v(const GLchar *, const OGL_TYPE *, GLsizei count = 1); \
void setUniform3v(const GLchar *, const OGL_TYPE *, GLsizei count = 1); \
void setUniform4v(const GLchar *, const OGL_TYPE *, GLsizei count = 1)

#define GLPROGRAM_CPP_SETTERS_3_ARGS(OGL_TYPE, TYPE_SUFFIX, TYPE_PREFIX) \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 1 ## TYPE_SUFFIX (getAttribId(name), v0); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 2 ## TYPE_SUFFIX (getAttribId(name), v0, v1); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 3 ## TYPE_SUFFIX (getAttribId(name), v0, v1, v2); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 4 ## TYPE_SUFFIX (getAttribId(name), v0, v1, v2, v3); \
} \
void GlProgram::setAttrib1v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 1 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib2v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 2 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib3v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 3 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib4v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## TYPE_PREFIX ## 4 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
}\
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0) \
{ assert(inUse()); glUniform1 ## TYPE_SUFFIX (getUniformId(name), v0); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1) \
{ assert(inUse()); glUniform2 ## TYPE_SUFFIX (getUniformId(name), v0, v1); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ assert(inUse()); glUniform3 ## TYPE_SUFFIX (getUniformId(name), v0, v1, v2); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ assert(inUse()); glUniform4 ## TYPE_SUFFIX (getUniformId(name), v0, v1, v2, v3); } \
void GlProgram::setUniform1v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform1 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform2v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform2 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform3v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform3 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform4v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform4 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); }

#define GLPROGRAM_CPP_SETTERS_2_ARGS(OGL_TYPE, TYPE_SUFFIX) \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 1 ## TYPE_SUFFIX (getAttribId(name), v0); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 2 ## TYPE_SUFFIX (getAttribId(name), v0, v1); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 3 ## TYPE_SUFFIX (getAttribId(name), v0, v1, v2); \
} \
void GlProgram::setAttrib(const GLchar *name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 4 ## TYPE_SUFFIX (getAttribId(name), v0, v1, v2, v3); \
} \
void GlProgram::setAttrib1v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 1 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib2v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 2 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib3v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 3 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
} \
void GlProgram::setAttrib4v(const GLchar *name, const OGL_TYPE *v) \
{ \
        assert(inUse()); \
        glVertexAttrib ## 4 ## TYPE_SUFFIX ## v (getAttribId(name), v); \
}\
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0) \
{ assert(inUse()); glUniform1 ## TYPE_SUFFIX (getUniformId(name), v0); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1) \
{ assert(inUse()); glUniform2 ## TYPE_SUFFIX (getUniformId(name), v0, v1); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2) \
{ assert(inUse()); glUniform3 ## TYPE_SUFFIX (getUniformId(name), v0, v1, v2); } \
void GlProgram::setUniform(const GLchar* name, OGL_TYPE v0, OGL_TYPE v1, OGL_TYPE v2, OGL_TYPE v3) \
{ assert(inUse()); glUniform4 ## TYPE_SUFFIX (getUniformId(name), v0, v1, v2, v3); } \
void GlProgram::setUniform1v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform1 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform2v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform2 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform3v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform3 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); } \
void GlProgram::setUniform4v(const GLchar* name, const OGL_TYPE* v, GLsizei count) \
{ assert(inUse()); glUniform4 ## TYPE_SUFFIX ## v (getUniformId(name), count, v); }

#endif //LOCK_MINER_GLDEFINE_H
