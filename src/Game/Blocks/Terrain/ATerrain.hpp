/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATerrain
*/

#pragma once
#include "IBlock.hpp"
#include "Sprite.hpp"

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
        void draw(sdf::Renderer &renderer) override;
    protected:
        ATerrain();
        bool _isConstructible;
        bool _isBlocking;
        std::pair<float, float> _pos;
        sdf::Sprite *_sprite;
};
