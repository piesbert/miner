/* Miner: actionmanager.cpp
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

#include "actionmanager.h"
#include "motionstate.h"
#include "log.h"

#include <SDL/SDL.h>

ActionManager::ActionManager() {
        defaultConfig();
}

ActionManager::~ActionManager() {
}

void ActionManager::defaultConfig() {
        m_actions[ACTION_NOTHING].configure(Action::DEVICE_UNKNOWN, 0);
        m_actions[ACTION_FORWARD].configure(Action::DEVICE_KEYBOARD, SDLK_w);
        m_actions[ACTION_BACKWARD].configure(Action::DEVICE_KEYBOARD, SDLK_s);
        m_actions[ACTION_STRAFE_LEFT].configure(Action::DEVICE_KEYBOARD, SDLK_a);
        m_actions[ACTION_STRAFE_RIGHT].configure(Action::DEVICE_KEYBOARD, SDLK_d);
        m_actions[ACTION_JUMP].configure(Action::DEVICE_KEYBOARD, SDLK_SPACE);
        m_actions[ACTION_USE].configure(Action::DEVICE_MOUSE, SDL_BUTTON_LEFT);
}

void ActionManager::handleEvent(const SDL_Event &ev) const {
        ActionId      action = ACTION_NOTHING;
        Action::State state  = Action::STATE_INVALID;

        /* don't check ACTION_NOTHING */
        for (int i = 1; i < ACTION_MAX; i++) {
                state = m_actions[i].isValid(ev);

                if (state) {
                        action = ActionId(i);
                        runAction(action, state);
                }
        }
}

void ActionManager::runAction(ActionId action, Action::State state) const {
        switch(action) {
                case ACTION_FORWARD:
                        MotionState::getInstance().setForward(state == Action::STATE_PRESSED ? true : false);
                        break;
                case ACTION_BACKWARD:
                        MotionState::getInstance().setBackward(state == Action::STATE_PRESSED ? true : false);
                        break;
                case ACTION_STRAFE_LEFT:
                        MotionState::getInstance().setLeft(state == Action::STATE_PRESSED ? true : false);
                        break;
                case ACTION_STRAFE_RIGHT:
                        MotionState::getInstance().setRight(state == Action::STATE_PRESSED ? true : false);
                        break;
                case ACTION_JUMP:
                        MotionState::getInstance().setJump(state == Action::STATE_PRESSED ? true : false);
                        break;
                case ACTION_USE:
                        LOGINF("USE " << (state == Action::STATE_PRESSED ? "on" : "off"));
                        break;
                default:
                        break;
        }
}
