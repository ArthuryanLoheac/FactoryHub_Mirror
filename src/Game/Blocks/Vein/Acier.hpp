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
        Acier() : AVein(Item("Acier")) {
            sdf::Texture texture("Assets/Acier.png");
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0), texture);
        };;
};
