/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Acier
*/

#pragma once
#include "AVein.hpp"

class Acier : public AVein
{
    public:
        Acier() : AVein(Item("SteelRaw")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 20),
                sdf::GetterTextures::instance->getTexture("Steel"));
        };;
};
