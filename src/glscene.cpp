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
        delete m_program;
        delete m_camera;
}

void GlScene::display() const {
        const glm::vec3 &pos = m_camera->getPosition();

        glClearColor( 0.0, 0.0, 0.0, 0.0 );
        glClear( GL_COLOR_BUFFER_BIT );

        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();
        //glMultMatrixf(glm::value_ptr(m_camera->matrix()));
        glTranslatef(pos.x, pos.y, pos.z);
        glColor3f( 1.0, 0.0, 0.0 );

        glBegin( GL_LINES );
        
        glVertex3f( 1.0, 1.0, 1.0 );
        glVertex3f( 1.0, - 1.0, 1.0 );

        glVertex3f( 1.0, - 1.0, 1.0 );
        glVertex3f( 1.0, - 1.0, - 1.0 );

        glVertex3f( 1.0, - 1.0, - 1.0 );
        glVertex3f( 1.0, 1.0, - 1.0 );

        glVertex3f( 1.0, 1.0, - 1.0 );
        glVertex3f( 1.0, 1.0, 1.0 );

        glVertex3f( - 1.0, 1.0, 1.0 );
        glVertex3f( - 1.0, - 1.0, 1.0 );

        glVertex3f( - 1.0, - 1.0, 1.0 );
        glVertex3f( - 1.0, - 1.0, - 1.0 );

        glVertex3f( - 1.0, - 1.0, - 1.0 );
        glVertex3f( - 1.0, 1.0, - 1.0 );

        glVertex3f( - 1.0, 1.0, - 1.0 );
        glVertex3f( - 1.0, 1.0, 1.0 );

        glVertex3f( 1.0, 1.0, 1.0 );
        glVertex3f( - 1.0, 1.0, 1.0 );

        glVertex3f( 1.0, - 1.0, 1.0 );
        glVertex3f( - 1.0, - 1.0, 1.0 );

        glVertex3f( 1.0, - 1.0, - 1.0 );
        glVertex3f( - 1.0, - 1.0, - 1.0 );

        glVertex3f( 1.0, 1.0, - 1.0 );
        glVertex3f( - 1.0, 1.0, - 1.0 );

        glEnd();

        glFlush();
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
}

void GlScene::move() {
        m_camera->move();
}

void GlScene::loadShaders() {
        m_shaders.push_back(GlShader::fromFile(SHADERS_PATH + "shader.vert", GL_VERTEX_SHADER));
        m_shaders.push_back(GlShader::fromFile(SHADERS_PATH + "shader.frag", GL_FRAGMENT_SHADER));

        m_program = new GlProgram(m_shaders);
}
