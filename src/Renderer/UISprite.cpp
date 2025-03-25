/*
** EPITECH PROJECT, 2025
** FactoryHub_Mirror
** File description:
** UISprite
*/

#include "UISprite.hpp"

sdf::UISprite::UISprite(const glm::vec3 &position,
    sdf::Texture &texture, float rotation)
    : sdf::Sprite(position, texture, rotation)
{
    _isUI = true;
}
