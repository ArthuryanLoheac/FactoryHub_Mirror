/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Charbon
*/

#pragma once
#include "AVein.hpp"

class Charbon : public AVein
{
    public:
        Charbon() : AVein(Item("CoalRaw")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0),
                sdf::GetterTextures::instance->getTexture("Coal"));
        };
};
