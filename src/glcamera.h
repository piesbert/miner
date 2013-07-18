/* Miner: glcamera.h
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

#if !defined(LOCK_MINER_GLCAMERA_H)
#define LOCK_MINER_GLCAMERA_H

#include <glm/glm.hpp>

class MotionState;

class GlCamera {
        public:
                GlCamera();
                virtual ~GlCamera();

                const glm::vec3 &getPosition() const;

                void setPosition(const glm::vec3 &);
                void offsetPosition(const glm::vec3 &);

                glm::mat4 getOrientation() const;
                void offsetOrientation(float, float);

                glm::vec3 forward() const;
                glm::vec3 right() const;

                float getFov() const;
                void setFov(float);

                void setAspect(float);
                void move();

                glm::mat4 matrix() const;
                glm::mat4 projection() const;
                glm::mat4 view() const;

        private:
                glm::vec3 m_position;

                float m_fov;
                float m_near;
                float m_far;
                float m_vAngle;
                float m_hAngle;
                float m_aspect;

                static const float s_fovMax;
                static const float s_fovMin;

                static const float s_vAngleMax;

                static MotionState &motionState;

                GlCamera(GlCamera const&); // do not implement
                GlCamera& operator=(GlCamera const&); // do not implement
}; // class GlCamera

#endif //LOCK_MINER_GLCAMERA_H
