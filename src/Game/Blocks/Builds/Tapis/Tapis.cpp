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
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 0),
        sdf::GetterTextures::instance->getTexture("Tapis"));
    _deltaMinPercent = 0.12f;
    _travelTime = 3.0f;
}
