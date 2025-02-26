/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** Sprite
*/

#pragma once
#include <glm/glm.hpp>
#include "Shader.hpp"
#include "Texture.hpp"
#include "Sdf.hpp"

namespace sdf
{
    class Sprite
    {
        public:
            Sprite(const glm::vec2 &position, const glm::vec2 &size,
                sdf::Texture &texture);

            void draw(sdf::Renderer &renderer);

            void setPosition(const glm::vec2 &position);
            void setSize(const glm::vec2 &size);

            unsigned int getTexture(void);
        private:
            sdf::Texture _texture;
            glm::vec2 _position;
            glm::vec2 _size;

            unsigned int _VAO;
            unsigned int _VBO;
            unsigned int _EBO;
    };
}
