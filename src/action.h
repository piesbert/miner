/* Miner: action.h
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

#if !defined(LOCK_MINER_ACTION_H)
#define LOCK_MINER_ACTION_H

union SDL_Event;

class Action {
        public:
                enum DeviceId {
                        DEVICE_UNKNOWN = 0,
                        DEVICE_KEYBOARD,
                        DEVICE_MOUSE
                };

                enum State {
                        STATE_INVALID = 0,
                        STATE_PRESSED,
                        STATE_RELEASED
                };

                Action();
                virtual ~Action();

                State isValid(const SDL_Event &) const;
                void  configure(DeviceId, int);

        private:
                DeviceId m_device;
                int      m_code;

                Action(Action const&); // do not implement
                Action& operator=(Action const&); // do not implement
}; // class Action

#endif //LOCK_MINER_ACTION_H
