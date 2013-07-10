/* Miner: glwindow.h
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

#if !defined(LOCK_MINER_GLWINDOW_H)
#define LOCK_MINER_GLWINDOW_H

class Config;
class GlScene;

class GlWindow {
        public:
                GlWindow(int *, char **);
                virtual ~GlWindow();

                void init(Config *, GlScene *);
                void start() const;

        private:
                void initGlew() const;
                
                static void render();

                static Config  *s_config;
                static GlScene *s_scene;

                GlWindow(GlWindow const&); // do not implement
                GlWindow operator=(GlWindow const&); // do not implement
}; // class GlWindow

#endif //LOCK_MINER_GLWINDOW_H
