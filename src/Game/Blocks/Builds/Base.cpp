/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Base
*/

#include "Base.hpp"

Base::Base()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 30.0f),
        sdf::GetterTextures::instance->getTexture("Base"), 0.0f);
    _AllItemAccepted = true;
    _noMax = true;
    setHp(1000);
}