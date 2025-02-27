/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Camera
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Camera.hpp"
#include <iostream>

#include <iostream>

sdf::Camera::Camera(glm::vec2 position, float zoom, float velocity)
    : _position(position), _zoom(zoom), _velocity(velocity)
{
}

glm::mat4 sdf::Camera::getTransformationMatrix(void)
{
    glm::mat4 transform = glm::mat4(1.0f);

    transform = glm::scale(transform, glm::vec3(_zoom, _zoom, 1.0f));
    transform = glm::translate(transform, glm::vec3(_position, 0.0f));
    return transform;
}

void sdf::Camera::move(sdf::Camera::Direction direction, double deltaTime, float _sizeX, float _sizeY)
{
    float distance = (_velocity * deltaTime) * (1 / _zoom);

    switch (direction) {
        case sdf::Camera::Direction::UP:
            _position = glm::vec2(_position.x, _position.y - distance);
            break;
        case sdf::Camera::Direction::DOWN:
            _position = glm::vec2(_position.x, _position.y + distance);
            break;
        case sdf::Camera::Direction::RIGHT:
            _position = glm::vec2(_position.x - distance, _position.y);
            break;
        case sdf::Camera::Direction::LEFT:
            _position = glm::vec2(_position.x + distance, _position.y);
            break;
    }
    _position.x = std::max(-_sizeX, std::min(_position.x, 1.f));
    _position.y = std::max(-_sizeY, std::min(_position.y, 1.f));
}

glm::vec2 sdf::Camera::getPosition(void)
{
    return _position;
}

float sdf::Camera::getZoom(void)
{
    return _zoom;
}

float sdf::Camera::getVelocity(void)
{
    return _velocity;
}


void sdf::Camera::setPosition(glm::vec2 position)
{
    _position = position;
}

void sdf::Camera::setZoom(float zoom)
{
    if (zoom >= 0.01f && zoom <= 2.0f)
        _zoom = zoom;
}

void sdf::Camera::setVelocity(float velocity)
{
    if (velocity >= 0.0f)
        _velocity = velocity;
}

