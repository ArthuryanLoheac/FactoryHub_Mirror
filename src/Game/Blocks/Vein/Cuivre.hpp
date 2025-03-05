/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Cuivre
*/

#pragma once
#include "AVein.hpp"

class Cuivre : public AVein
{
    public:
        Cuivre() : AVein(Item("Copper")) {
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0),
                sdf::GetterTextures::instance->getTexture("Copper"));
        };
};
