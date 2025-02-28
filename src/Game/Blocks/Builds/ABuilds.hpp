/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#pragma once
#include "IBlock.hpp"
#include "Item.hpp"
#include "Sprite.hpp"
#include "Sdf.hpp"

class ABuilds : public IBlock
{
    public:
        virtual bool addElement(Item item);
        virtual bool outElement(std::string name);
        void setPosX(float posX) override;
        void setPosY(float posY) override;
        int getHp() const;
        int getHpMax() const;
        void setHp(int hp);
        void takeDamage(int dmg);

        float getPosX() const override;
        float getPosY() const override;
        bool getIsConstructible() const override;
        bool getIsBlocking() const override;
        virtual void update(float deltaTime, MapGrid map) = 0;

    protected:
        ABuilds();
        float _posY;
        float _posX;

        int _hp;
        int _hpMax;

        bool _isConstructible;
        bool _isBlocking;
        
        std::vector<Item> _AcceptedItems;
        bool _AllItemAccepted;
        
        std::vector<Item> _Ins;
        std::vector<Item> _Outs;
        size_t _MaxIn;
        size_t _MaxOut;
        bool _noMax;
        sdf::Sprite *_sprite;
};
