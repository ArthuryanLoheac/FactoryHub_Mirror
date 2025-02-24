/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** IEntity
*/

#pragma once
#include <utility>

class IEntity
{
public:
    virtual ~IEntity() = default;

    virtual void update(float deltaTime) = 0;
    virtual std::pair<float, float> getPositionPixel() = 0;
    virtual std::pair<std::size_t, std::size_t> getPositionGrid() = 0;
};
