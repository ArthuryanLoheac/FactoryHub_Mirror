/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Salpetre
*/

#pragma once
#include "AVein.hpp"

class Salpetre : public AVein
{
    public:
        Salpetre() : AVein(Item("Salpetre")) {
            sdf::Texture texture("Assets/Salpetre.png");
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0), texture);
        };
};
