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
        Charbon() : AVein(Item("Charbon")) {
            sdf::Texture texture("Assets/Charbon.png");
            _sprite = new sdf::Sprite(glm::vec3(0, 0, 0), texture);
        };
};
