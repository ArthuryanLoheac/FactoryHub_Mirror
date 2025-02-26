/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#pragma once
#include "IBlock.hpp"
#include "Item.hpp"

class AVein : public IBlock
{
    protected:
        float _posY;
        float _posX;
        bool _isConstructible;
        bool _isBlocking;
    
        Item _ressource;
        AVein(Item item);
    public:
        Item getRessource() const;
        void setPosX(float posX) override;
        void setPosY(float posY) override;
        float getPosX() const override;
        float getPosY() const override;
        bool getIsConstructible() const override;
        bool getIsBlocking() const override;
        virtual void update(float deltaTime, MapGrid map) override;
};
