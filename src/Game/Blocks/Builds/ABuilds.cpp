/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#include "ABuilds.hpp"

bool ABuilds::addElement(Item item)
{
    if (_noMax == false && _Ins.size() >= _MaxIn)
        return false;
    if (_AllItemAccepted == false) {
        for (Item &str: _AcceptedItems) {
            if (str.getName() == item.getName()) {
                _Ins.push_back(item);
                return true;
            }
        }
        return false;
    }
    _Ins.push_back(item);
    return true;
}

bool ABuilds::outElement(std::string name)
{
    int i = 0;

    for (Item &it: _Ins) {
        if (it.getName() == name) {
            _Outs.erase(_Outs.begin() + i);
            return true;
        }
        i++;
    }
    return false;
}

ABuilds::ABuilds()
{
    _AllItemAccepted = false;
    _noMax = false;
    _isConstructible = false;
    _isBlocking = true;
}

#pragma region GettersSetters

void ABuilds::setPosX(float posX)
{
    _posX = posX;
}

void ABuilds::setPosY(float posY)
{
    _posY = posY;
}

int ABuilds::getHp() const
{
    return _hp;
}

int ABuilds::getHpMax() const
{
    return _hpMax;
}

void ABuilds::setHp(int hp)
{
    _hp = hp;
    _hpMax = hp;
}

void ABuilds::takeDamage(int dmg)
{
    _hp -= dmg;
}

float ABuilds::getPosX() const
{
    return _posX;
}

float ABuilds::getPosY() const
{
    return _posY;
}

bool ABuilds::getIsConstructible() const
{
    return _isConstructible;
}

bool ABuilds::getIsBlocking() const
{
    return _isBlocking;
}

#pragma endregion GettersSetters
