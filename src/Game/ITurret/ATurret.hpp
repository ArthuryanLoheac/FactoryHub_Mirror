/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATurret
*/

#pragma once
#include "ITurret.hpp"
#include "IEntity.hpp"
#include "IBlock.hpp"
#include <tgmath.h>

class ATurret : public ITurret
{
    public:
        void update(float deltaTime) override;
        void Shoot() override;
        bool IsInRange(IEntity *enenmy) override;
        bool IsInRange(IBlock *block) override;
        bool AddAmmo(Item item) override;

        void setHp(int hp) override;
        int getHp() const override;
        int getMaxHp() const override;
        float getSpeedRate() const override;
        float getRange() const override;
        int getnbAmmoShoot() override;
        std::pair<float, float> &getPos() override;
        void setPos(std::pair<float, float> pos) override;
        std::vector<Item> &getAmmos() override;
        int getMaxStock() override;
        int getTier() override;

    protected:
        ATurret();
        int _hp;
        int _maxHp;
        float _speedRate;
        float _range;
        int _nbAmmoShoot;
        std::pair<float, float> _pos;
        std::vector<Item> _ammos;
        int _maxStock;
        int _tier;
};
