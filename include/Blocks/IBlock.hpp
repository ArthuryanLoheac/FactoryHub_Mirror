/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** IBlock
*/

#pragma once
#include <stdexcept>
#include <vector>

class IBlock
{
    public:
        virtual void setPosX(float posX) = 0;
        virtual void setPosY(float posY) = 0;
        virtual float getPosX() const = 0;
        virtual float getPosY() const = 0;
        virtual bool getIsConstructible() const = 0;
        virtual bool getIsBlocking() const = 0;
        virtual void update(float deltaTime) = 0;
    protected:
        float _posY;
        float _posX;
        bool _isConstructible;
        bool _isBlocking;
};
