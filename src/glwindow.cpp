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

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

GlWindow::GlWindow(int *c, char **v) 
: m_config(0), m_scene(0) {
        m_config = new Config();
        m_scene  = new GlScene(m_config);
}

GlWindow::~GlWindow() {
        delete m_scene;
        delete m_config;

        SDL_Quit();
}

void GlWindow::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                LOGERR("SDL init failed: " << SDL_GetError());
        }

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        
        resize(m_config->glWidth(), m_config->glHeight());
}

void GlWindow::resize(int width, int height) const {
        const SDL_VideoInfo *vInfo    = 0;
        const SDL_Surface   *vSurface = 0;

        vInfo = SDL_GetVideoInfo();

        if (0 == vInfo) {
                LOGERR("Video query failed: " << SDL_GetError());
        }

        vSurface = SDL_SetVideoMode(width, height, vInfo->vfmt->BitsPerPixel, m_config->glMode());

        if (0 == vSurface) {
                LOGERR("Video mode set failed: " << SDL_GetError());
        }

        m_scene->reshape(width, height);

        m_config->set_glWidth(width);
        m_config->set_glHeight(height);
}

void GlWindow::start() const {
        SDL_Event ev;
        bool running;
        
        running = true;

        while (running) {
                while (SDL_PollEvent(&ev)) {
                        switch (ev.type) {
                                case SDL_QUIT: {
                                        running = false;
                                        break;
                                }
                                case SDL_VIDEORESIZE: {
                                        resize(ev.resize.w, ev.resize.h);
                                        break;
                                }
                                default: {
                                        break;
                                }
                        }
                }

                m_scene->display();
                SDL_GL_SwapBuffers();
        }
}
