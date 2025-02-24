/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** AEntity
*/

#pragma once
#include "IEntity.hpp"

class AEntity
{
    public:
        ~AEntity();

        void update(float deltaTime);
        std::pair<float, float> getPositionPixel();
        std::pair<std::size_t, std::size_t> getPositionGrid();
    protected:
        std::pair<float, float> _pos_pixel;
        std::pair<std::size_t, std::size_t>_pos_grid;
};
