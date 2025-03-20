/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Eau
*/

#pragma once
#include "AVein.hpp"

class Eau : public AVein
{
    public:
        Eau() : AVein(Item("WaterRaw")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 1),
                sdf::GetterTextures::instance->getTexture("Water"));
        };
};
