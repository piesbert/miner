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

Config  *GlWindow::s_config = 0;
GlScene *GlWindow::s_scene  = 0;

GlWindow::GlWindow(int *c, char **v) {
        glutInit(c, v);
}

GlWindow::~GlWindow() {
}

void GlWindow::init(Config *config, GlScene *scene) {
        s_config = config;
        s_scene  = scene;

        glutInitDisplayMode(s_config->glMode());
        glutInitWindowSize(s_config->glWidth(), s_config->glHeight());

        glutCreateWindow(APP_NAME);

        initGlew();
}

void GlWindow::start() const {
        glutDisplayFunc(render);
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

void GlWindow::render() {
        if (s_scene) {
                s_scene->render();
        }
}
