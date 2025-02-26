/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATerrain
*/

#pragma once
#include "IBlock.hpp"

class ATerrain : public IBlock
{
    public:
        bool getIsConstructible() const override;
        bool getIsBlocking() const override;
        void setPosX(float posX) override;
        void setPosY(float posY) override;
        float getPosX() const override;
        float getPosY() const override;
        void update(float deltaTime, MapGrid map) override;
    protected:
        ATerrain();
        bool _isConstructible;
        bool _isBlocking;
        std::pair<float, float> _pos;
};
