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
        Cuivre() : AVein(Item("Cuivre")) {
            sdf::Texture texture("Assets/Cuivre.png");
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0), texture);
        };
};
