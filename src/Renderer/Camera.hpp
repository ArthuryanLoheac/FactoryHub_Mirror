/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Camera
*/

#pragma once
#include <glm/glm.hpp>

namespace sdf
{
    class Camera
    {
        public:
            enum Direction {
                UP,
                RIGHT,
                DOWN,
                LEFT,
            };
            Camera(glm::vec2 position = glm::vec2(0.0f, 0.0f),
                float zoom = 1.0f, float velocity = 10.0f);

            glm::mat4 getTransformationMatrix(void);
            void move(sdf::Camera::Direction direction, double deltaTime, float _sizeX, float _sizeY);

            glm::vec2 getPosition(void);
            float getZoom(void);
            float getVelocity(void);

            void setPosition(glm::vec2 position);
            void setZoom(float zoom);
            void setVelocity(float velocity);

        private:
            glm::vec2 _position;
            float _zoom;
            float _velocity;
    };
}
