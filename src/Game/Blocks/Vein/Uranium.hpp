/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Uranium
*/

#pragma once
#include "AVein.hpp"

class Uranium : public AVein
{
    public:
        Uranium() : AVein(Item("Uranium")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0),
                sdf::GetterTextures::instance->getTexture("Uranium"));
        };
};
