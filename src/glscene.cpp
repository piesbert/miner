/* Miner: glscene.cpp
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

#include "glscene.h"
#include "glcamera.h"
#include "glprogram.h"
#include "gltexture.h"
#include "build.h"
#include "config.h"
#include "log.h"

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

GlScene::GlScene(Config *config) :
m_camera(0),
m_config(config),
m_program(0) {
        m_camera = new GlCamera();
}

GlScene::~GlScene() {
        delete m_texture;
        delete m_program;
        delete m_camera;
}

void GlScene::display() const {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(m_program->getId());
        m_program->setUniform("camera", m_camera->matrix());

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_texture->getId());
        m_program->setUniform("tex", 0);
        
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3*2*6);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glUseProgram(0);
}

void GlScene::reshape(int width, int height) {
        GLdouble aspect;

        glViewport(0, 0, width, height);
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();

        if( height > 0 ) {
                aspect = width / (GLdouble)(height);
        }

        gluPerspective((GLdouble)(m_config->glFov()), aspect, 0.01, 100.0 );
        if (0 != m_program) {
                display();
        }

        m_camera->setAspect(aspect);
}

void GlScene::move() {
        m_camera->move();
}

void GlScene::loadShaders() {
        m_shaders.push_back(GlShader::fromFile(SHADERS_PATH + "shader.vert", GL_VERTEX_SHADER));
        m_shaders.push_back(GlShader::fromFile(SHADERS_PATH + "shader.frag", GL_FRAGMENT_SHADER));

        m_program = new GlProgram(m_shaders);

        m_texture = new GlTexture("cliff_rock.png");
        
        
        glGenVertexArrays(1, &m_vao);
        glBindVertexArray(m_vao);

        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        GLfloat vertexData[] = {
                -1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
                1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f,-1.0f, 1.0f, 0.0f, 1.0f,

                -1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
                1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

                -1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
                1.0f,-1.0f, 1.0f,  1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
                1.0f,-1.0f, 1.0f,  1.0f, 0.0f,
                1.0f, 1.0f, 1.0f,  1.0f, 1.0f,
                -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
                //-1.0f,-1.0f, 1.0f, 1.0f, 0.0f,
                //1.0f,-1.0f, 1.0f,  0.0f, 0.0f,
                //-1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                //1.0f,-1.0f, 1.0f,  0.0f, 0.0f,
                //1.0f, 1.0f, 1.0f,  0.0f, 1.0f,
                //-1.0f, 1.0f, 1.0f, 1.0f, 1.0f,

                -1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f,-1.0f, 1.0f, 1.0f,
                1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                -1.0f, 1.0f,-1.0f, 1.0f, 1.0f,
                1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
                //-1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                //-1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
                //1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                //1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                //-1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
                //1.0f, 1.0f,-1.0f, 1.0f, 1.0f,

                -1.0f,-1.0f, 1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
                -1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                -1.0f,-1.0f, 1.0f, 1.0f, 0.0f,
                -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                -1.0f, 1.0f,-1.0f, 0.0f, 1.0f,
                //-1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
                //-1.0f, 1.0f,-1.0f, 1.0f, 0.0f,
                //-1.0f,-1.0f,-1.0f, 0.0f, 0.0f,
                //-1.0f,-1.0f, 1.0f, 0.0f, 1.0f,
                //-1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                //-1.0f, 1.0f,-1.0f, 1.0f, 0.0f,

                1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
                1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                1.0f, 1.0f,-1.0f, 1.0f, 1.0f,
                1.0f,-1.0f, 1.0f, 0.0f, 0.0f,
                1.0f, 1.0f,-1.0f, 1.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 0.0f, 1.0f
                //1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
                //1.0f,-1.0f,-1.0f, 1.0f, 0.0f,
                //1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
                //1.0f,-1.0f, 1.0f, 1.0f, 1.0f,
                //1.0f, 1.0f,-1.0f, 0.0f, 0.0f,
                //1.0f, 1.0f, 1.0f, 0.0f, 1.0f
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
        glEnableVertexAttribArray(m_program->getAttribId("vert"));
        glVertexAttribPointer(m_program->getAttribId("vert"), 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

        glEnableVertexAttribArray(m_program->getAttribId("vertTexCoord"));
        glVertexAttribPointer(m_program->getAttribId("vertTexCoord"), 2, GL_FLOAT, GL_TRUE, 5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
}
