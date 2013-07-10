/* Miner: glscene.h
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

#if !defined(LOCK_MINER_GLSCENE_H)
#define LOCK_MINER_GLSCENE_H

class Config;

class GlScene {
        public:
                GlScene(Config *);
                virtual ~GlScene();

                void init();

                void display() const;
                void reshape(int, int) const;

        private:
                const Config *m_config;

                static GlScene *s_this;

                static void f_display();
                static void f_reshape(int, int);

                GlScene(GlScene const&); // do not implement
                GlScene operator=(GlScene const&); // do not implement
}; // class GlScene

#endif //LOCK_MINER_GLSCENE_H
