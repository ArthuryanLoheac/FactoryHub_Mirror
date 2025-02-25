/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Sprite
*/

#pragma once
#include <glm.hpp>
#include "Shader.hpp"

namespace sdf
{
    class Sprite
    {
        public:
            Sprite(const glm::vec2 &position, const glm::vec2 &size);

            void draw(void);

            void setPosition(const glm::vec2 &position);
            void setSize(const glm::vec2 &size);
        private:
            glm::vec2 _position;
            glm::vec2 _size;

            unsigned int _VAO;
            unsigned int _VBO;
            unsigned int _EBO;
    };
}
