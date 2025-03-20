/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** UISprite
*/

#pragma once

#include "Sprite.hpp"

namespace sdf
{
    class UISprite : public Sprite
    {
        public:
            UISprite(const glm::vec3 &position,
                sdf::Texture &texture,
                float rotation = SDF_UP);
    };
}
