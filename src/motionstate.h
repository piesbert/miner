/* Miner: motionstate.h
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

#if !defined(LOCK_MINER_MOTIONSTATE_H)
#define LOCK_MINER_MOTIONSTATE_H

class MotionState {
        public:
                static MotionState& getInstance();
                virtual ~MotionState();

                void setForward(bool);
                void setBackward(bool);
                void setLeft(bool);
                void setRight(bool);
                void setJump(bool);
                void setPitch(float);
                void setYaw(float);

                bool getForward()  const { return m_forward; };
                bool getBackward() const { return m_backward; };
                bool getLeft()     const { return m_left; };
                bool getRight()    const { return m_right; };

                float getPitch()   const { return m_pitch; };
                float getYaw()     const { return m_yaw; };

        private:
                bool m_forward;
                bool m_backward;
                bool m_left;
                bool m_right;
                bool m_jump;

                float m_pitch;
                float m_yaw;

                MotionState();
                MotionState(MotionState const&); // do not implement
                MotionState& operator=(MotionState const&); // do not implement
}; // class MotionState

#endif //LOCK_MINER_MOTIONSTATE_H
