/* Miner: motionstate.cpp
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

#include "motionstate.h"

MotionState::MotionState() {
        m_forward  = false;
        m_backward = false;
        m_left     = false;
        m_right    = false;
        m_pitch    = 0.0f;
        m_yaw      = 0.0f;
}

MotionState::~MotionState() {
}

MotionState& MotionState::getInstance() {
        static MotionState instance;
        return instance;
}

void MotionState::setForward(bool state) {
        if (true == (m_forward = state)) {
                m_backward = false;
        }
}

void MotionState::setBackward(bool state) {
        if (true == (m_backward = state)) {
                m_forward = false;
        }
}

void MotionState::setLeft(bool state) {
        if (true == (m_left = state)) {
                m_right = false;
        }
}

void MotionState::setRight(bool state) {
        if (true == (m_right = state)) {
                m_left = false;
        }
}

void MotionState::setJump(bool jump) {
        m_jump = jump;
}

void MotionState::setPitch(float pitch) {
        m_pitch = pitch;
}

void MotionState::setYaw(float yaw) {
        m_yaw = yaw;
}
