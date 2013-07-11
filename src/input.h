/* Miner: input.h
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

#if !defined(LOCK_MINER_INPUT_H)
#define LOCK_MINER_INPUT_H

union SDL_Event;

class ActionManager;

class Input {
        public:
                Input();
                virtual ~Input();

                void handle(const SDL_Event &) const;

        private:
                ActionManager *m_actionManager;

                Input(Input const&); // do not implement
                Input operator=(Input const&); // do not implement
}; // class Input

#endif //LOCK_MINER_INPUT_H
