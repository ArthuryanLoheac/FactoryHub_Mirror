/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#pragma once
#include "IBlock.hpp"
#include "Item.hpp"
#include "Sprite.hpp"

class AVein : public IBlock
{
    protected:
        float _posY;
        float _posX;
        size_t posXGrid;
        size_t posYGrid;
        bool _isConstructible;
        bool _isBlocking;
    
        Item _ressource;
        AVein(Item item);
        sdf::Sprite *_sprite;
    public:
        Item getRessource() const;
        void setPosX(float posX) override;
        void setPosY(float posY) override;
        float getPosX() const override;
        float getPosY() const override;
        void setPosXGrid(size_t posX) override;
        void setPosYGrid(size_t posY) override;
        virtual void setDirection(Direction direction) override;
        size_t getPosXGrid() const override;
        size_t getPosYGrid() const override;
        bool getIsConstructible() const override;
        bool getIsBlocking() const override;
        virtual void update(float deltaTime, MapGrid map) override;
        void draw(sdf::Renderer &renderer) override;
};
