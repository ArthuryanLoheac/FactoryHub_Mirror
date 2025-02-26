/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** IEntity
*/

#pragma once
#include <utility>
#include "MapGrid.hpp"

class IEntity
{
public:
    virtual ~IEntity() = default;

    virtual void update(float deltaTime, MapGrid map) = 0;
    virtual std::pair<float, float> getPositionPixel() = 0;
    virtual std::pair<std::size_t, std::size_t> getPositionGrid() = 0;
};
