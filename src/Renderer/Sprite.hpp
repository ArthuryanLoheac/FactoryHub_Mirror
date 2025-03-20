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

#define SDF_UP 0
#define SDF_RIGHT 90
#define SDF_DOWN 180
#define SDF_LEFT 270

namespace sdf
{
    class Sprite
    {
        public:
            Sprite(const glm::vec3 &position,
                sdf::Texture &texture,
                float rotation = SDF_UP);

            void draw(sdf::Renderer &renderer);

            void setPosition(const glm::vec2 &position);
            void setLayer(float layer);
            void setDirection(float direction);
            unsigned int getTexture(void);
        protected:
            bool _isUI;
        private:
            sdf::Texture _texture;
            glm::vec3 _position;
            float _direction;

            unsigned int _VAO;
            unsigned int _VBO;
            unsigned int _EBO;
    };
}
