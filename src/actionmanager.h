/* Miner: actionmanager.h
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

#if !defined(LOCK_MINER_ACTIONMANAGER_H)
#define LOCK_MINER_ACTIONMANAGER_H

#include "action.h"

union SDL_Event;

class ActionManager {
        public:
                enum ActionId {
                        ACTION_NOTHING = 0,
                        ACTION_FORWARD,
                        ACTION_BACKWARD,
                        ACTION_STRAFE_LEFT,
                        ACTION_STRAFE_RIGHT,
                        ACTION_JUMP,
                        ACTION_USE,
                        ACTION_MAX
                };
                
                void configure(ActionId, Action::DeviceId, int);
                void handleEvent(const SDL_Event &) const;

                ActionManager();
                virtual ~ActionManager();

        private:
                Action m_actions[ACTION_MAX];

                void defaultConfig();
                void runAction(ActionId, Action::State) const;

                ActionManager(ActionManager const&); // do not implement
                ActionManager operator=(ActionManager const&); // do not implement
}; // class ActionManager

#endif //LOCK_MINER_ACTIONMANAGER_H
