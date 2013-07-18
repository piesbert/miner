/* Miner: glcamera.cpp
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

#include "glcamera.h"
#include "motionstate.h"

#include <glm/gtc/matrix_transform.hpp>

const float GlCamera::s_fovMax = 90.0f;
const float GlCamera::s_fovMin = 20.0f;
const float GlCamera::s_vAngleMax = 80.0f;

GlCamera::GlCamera() :
m_position(0.0f, 0.0f, 3.0f),
m_fov(50.0f),
m_near(0.01f),
m_far(100.0f),
m_vAngle(0.0f),
m_hAngle(0.0f),
m_aspect(0.0f) {
}

GlCamera::~GlCamera() {
}

const glm::vec3 &GlCamera::getPosition() const {
        return m_position;
}

void GlCamera::setPosition(const glm::vec3 &position) {
            m_position = position;
}

void GlCamera::offsetPosition(const glm::vec3 &offset) {
            m_position += offset;
}

float GlCamera::getFov() const {
        return m_fov;
}

void GlCamera::setFov(float fov) {
        if (fov > s_fovMax) {
                fov = s_fovMax;
        }
        else if (fov < s_fovMin) {
                fov = s_fovMin;
        }

        m_fov = fov;
}

glm::mat4 GlCamera::getOrientation() const {
        glm::mat4 retval;

        retval = glm::rotate(retval, m_vAngle, glm::vec3(1, 0, 0));
        retval = glm::rotate(retval, m_hAngle, glm::vec3(0, 1, 0));

        return retval;
}

void GlCamera::offsetOrientation(float va, float ha) {
        m_vAngle += va;

        if (m_vAngle > s_vAngleMax) {
                m_vAngle = s_vAngleMax;
        }
        if (m_vAngle < -s_vAngleMax) {
                m_vAngle = -s_vAngleMax;
        }

        m_hAngle += ha;

        while (m_hAngle > 360.0f) m_hAngle -= 360.0f;
        while (m_hAngle < 0.0f)   m_hAngle += 360.0f;
}

glm::vec3 GlCamera::forward() const {
        glm::vec4 retval;
        glm::mat4 fdir;

        fdir = glm::rotate(fdir, m_hAngle, glm::vec3(0, 1, 0));
        retval = glm::inverse(fdir) * glm::vec4(0,0,-1,1);

        return glm::vec3(retval);
}

glm::vec3 GlCamera::right() const {
        glm::vec4 retval;

        retval = glm::inverse(getOrientation()) * glm::vec4(1,0,0,1);
        return glm::vec3(retval);
}

void GlCamera::setAspect(float aspect) {
        m_aspect = aspect;
}

void GlCamera::move() {
       if (MotionState::getInstance().getForward()) {
               offsetPosition(0.1f * forward());
       }

       if (MotionState::getInstance().getBackward()) {
               offsetPosition(0.1f * -forward());
       }

       if (MotionState::getInstance().getLeft()) {
               offsetPosition(0.1f * -right());
       }

       if (MotionState::getInstance().getRight()) {
               offsetPosition(0.1f * right());
       }

       offsetOrientation(MotionState::getInstance().getPitch(), MotionState::getInstance().getYaw());
}

glm::mat4 GlCamera::matrix() const {
            return projection() * view();
}

glm::mat4 GlCamera::projection() const {
            return glm::perspective(m_fov, m_aspect, m_near, m_far);
}

glm::mat4 GlCamera::view() const {
            return getOrientation() * glm::translate(glm::mat4(), -m_position);
}
