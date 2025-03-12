/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** IBlock
*/

#pragma once
#include "MapGrid.hpp"
#include <stdexcept>
#include <vector>
#include <memory>
#include "Sdf.hpp"
#include "GetterTextures.hpp"
#include "Direction.hpp"

class MapGrid;

class IBlock
{
    public:
        virtual void setPosX(float posX) = 0;
        virtual void setPosY(float posY) = 0;
        virtual float getPosX() const = 0;
        virtual float getPosY() const = 0;
        virtual void setPosXGrid(size_t posX) = 0;
        virtual void setPosYGrid(size_t posY) = 0;
        virtual void setDirection(Direction direction) = 0;
        virtual size_t getPosXGrid() const = 0;
        virtual size_t getPosYGrid() const = 0;
        virtual bool getIsConstructible() const = 0;
        virtual bool getIsBlocking() const = 0;
        virtual void update(float deltaTime, MapGrid map) = 0;
        virtual void draw(sdf::Renderer &renderer) = 0;
        virtual bool isUpdatable() = 0;
};
