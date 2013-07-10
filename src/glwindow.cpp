/* Miner: glwindow.cpp
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

#include "glwindow.h"
#include "glscene.h"
#include "build.h"
#include "config.h"
#include "log.h"

#include <GL/glew.h>
#include <GL/glut.h>

GlWindow::GlWindow(int *c, char **v) 
: m_config(0), m_scene(0) {
        glutInit(c, v);
        
        m_config = new Config();
        m_scene  = new GlScene(m_config);
}

GlWindow::~GlWindow() {
        delete m_scene;
        delete m_config;
}

void GlWindow::init() {
        glutInitDisplayMode(m_config->glMode());
        glutInitWindowSize(m_config->glWidth(), m_config->glHeight());

        glutCreateWindow(APP_NAME);

        initGlew();
}

void GlWindow::start() const {
        m_scene->init();
        
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glutMainLoop();
}

void GlWindow::initGlew() const {
        GLenum res;

        res = glewInit();

        if (GLEW_OK != res) {
                LOGERR("GLEW init error: " << glewGetErrorString(res));
        }
}
