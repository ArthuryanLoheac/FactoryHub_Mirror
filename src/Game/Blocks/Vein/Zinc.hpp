/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Zinc
*/

#pragma once
#include "AVein.hpp"

class Zinc : public AVein
{
    public:
        Zinc() : AVein(Item("ZincRaw")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 1),
                sdf::GetterTextures::instance->getTexture("Zinc"));
        };
};
