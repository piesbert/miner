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

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL/SDL.h>

#include "glwindow.h"
#include "glscene.h"
#include "glprogram.h"
#include "actionmanager.h"
#include "motionstate.h"
#include "build.h"
#include "config.h"
#include "log.h"

GlWindow::GlWindow() :
m_config(0),
m_scene(0),
m_actionManager(0),
m_running(true) {
        m_config = new Config();
        m_scene  = new GlScene(m_config);

        m_actionManager  = new ActionManager(this);
}

GlWindow::~GlWindow() {
        delete m_actionManager;
        delete m_scene;
        delete m_config;

        SDL_Quit();
        LOGINF("Closing app .. done!");
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
        
        if (glewInit() != GLEW_OK) {
                LOGERR("GLEW init failed");
        }

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        m_scene->loadShaders();
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

        SDL_ShowCursor(0);
        SDL_WM_GrabInput(SDL_GRAB_ON);

        m_scene->reshape(width, height);

        m_config->set_glWidth(width);
        m_config->set_glHeight(height);
}

void GlWindow::start() {
        SDL_Event ev;
        MotionState &motion = MotionState::getInstance();

        bool first = true;
        unsigned int ticks = 0;

        m_ticks = SDL_GetTicks();
        
        while (m_running) {

                motion.setYaw(0.0f);
                motion.setPitch(0.0f);

                while (SDL_PollEvent(&ev)) {
                        switch (ev.type) {
                                case SDL_QUIT: {
                                        quit();
                                        break;
                                }
                                case SDL_VIDEORESIZE: {
                                        resize(ev.resize.w, ev.resize.h);
                                        break;
                                }
                                case SDL_KEYDOWN:
                                case SDL_KEYUP:
                                case SDL_MOUSEBUTTONDOWN:
                                case SDL_MOUSEBUTTONUP: {
                                        m_actionManager->handleEvent(ev);
                                        break;
                                }
                                case SDL_MOUSEMOTION: {
                                        if (first) {
                                                first = false;
                                        } else {
                                                motion.setYaw((ev.motion.xrel * 0.5));
                                                motion.setPitch((ev.motion.yrel * 0.5));
                                        }
                                        break;
                                }
                                default: {
                                        break;
                                }
                        }
                }

                ticks = SDL_GetTicks();
                if (ticks - m_ticks > 25) {
                        m_ticks = ticks;
                        m_scene->move();
                }

                m_scene->display();
                SDL_GL_SwapBuffers();
        }
}

void GlWindow::quit() {
        m_running = false;
}
