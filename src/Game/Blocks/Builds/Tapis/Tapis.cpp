/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Tapis
*/

#include "Tapis.hpp"

Tapis::Tapis()
    : ATapis()
{
    sdf::Texture textureTapis = sdf::Texture("Assets/tapis.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureTapis);
    _deltaMinPercent = 0.12f;
    _travelTime = 3.0f;
}
