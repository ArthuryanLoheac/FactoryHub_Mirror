/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATurret
*/
#include "ATurret.hpp"


void ATurret::update(float deltaTime, MapGrid map)
{
    deltaTime = deltaTime;
    map = map;
}

void ATurret::Shoot()
{
    for (int i = 0; i < _nbAmmoShoot; i++) {
        if (_ammos.size() == 0)
            return;
        _ammos.pop_back();
    }
}

bool ATurret::IsInRange(IEntity *enenmy)
{
    float dist = sqrt(pow(enenmy->getPositionPixel().first - _pos.first, 2) +
                    pow(enenmy->getPositionPixel().second - _pos.second, 2));
    return dist <= _range;
}

bool ATurret::IsInRange(IBlock *block)
{
    float dist = sqrt(pow(block->getPosX() - _pos.first, 2) +
                    pow(block->getPosY() - _pos.second, 2));
    return dist <= _range;
}

bool ATurret::AddAmmo(Item item)
{
    if (_ammos.size() >= _maxStock)
        return (false);
    _ammos.push_back(item);
    return (true);
}

void ATurret::setHp(int hp)
{
    _hp = hp;
}

int ATurret::getHp() const
{
    return _hp;
}

int ATurret::getMaxHp() const
{
    return _maxHp;
}

float ATurret::getSpeedRate() const
{
    return _speedRate;
}

float ATurret::getRange() const
{
    return _range;
}

int ATurret::getnbAmmoShoot()
{
    return _nbAmmoShoot;
}

std::pair<float, float> &ATurret::getPos()
{
    return _pos;
}

void ATurret::setPos(std::pair<float, float> pos)
{
    _pos = pos;
}

std::vector<Item> &ATurret::getAmmos()
{
    return _ammos;
}

int ATurret::getMaxStock()
{
    return _maxStock;
}

int ATurret::getTier()
{
    return _tier;
}

ATurret::ATurret()
{
    _hp = 0;
    _maxHp = 0;
    _speedRate = 0;
    _range = 0;
    _nbAmmoShoot = 0;
    _pos = std::make_pair(0, 0);
    _maxStock = 0;
    _tier = 0;
}