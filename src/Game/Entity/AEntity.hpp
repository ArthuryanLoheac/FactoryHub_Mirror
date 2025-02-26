/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** AEntity
*/

#pragma once
#include "IEntity.hpp"

class AEntity : public IEntity
{
    public:
        ~AEntity();

        virtual void update(float deltaTime, MapGrid map) override;
        std::pair<float, float> getPositionPixel() override;
        std::pair<std::size_t, std::size_t> getPositionGrid() override;
    protected:
        std::pair<float, float> _pos_pixel;
        std::pair<std::size_t, std::size_t> _pos_grid;
};
