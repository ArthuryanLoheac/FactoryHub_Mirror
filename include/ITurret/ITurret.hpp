/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ITurret
*/

#pragma once
#include "IEntity.hpp"
#include "IBlock.hpp"
#include "Item.hpp"

class ITurret
{
    public:
        ITurret() = default;
        virtual void update(float deltaTime) = 0;
        virtual void Shoot() = 0;
        virtual bool IsInRange(IEntity *enenmy) = 0;
        virtual bool IsInRange(IBlock *block) = 0;
        virtual bool AddAmmo(Item item) = 0;

        virtual void setHp(int hp) = 0;
        virtual int getHp() const = 0;
        virtual int getMaxHp() const = 0;
        virtual float getSpeedRate() const = 0;
        virtual float getRange() const = 0;
        virtual int getnbAmmoShoot() = 0;
        virtual std::pair<float, float> &getPos() = 0;
        virtual void setPos(std::pair<float, float> pos) = 0;
        virtual std::vector<Item> &getAmmos() = 0;
        virtual int getMaxStock() = 0;
        virtual int getTier() = 0;
};

