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

Item *ABuilds::outElement()
{
    if (_Outs.size() == 0)
        return nullptr;
    Item *item = &_Outs[0];
    _Outs.erase(_Outs.begin());
    return item;
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
    _updatable = false;
    _isConstructible = false;
    _isBlocking = true;
    sdf::Texture textureStone = sdf::Texture("Assets/Error.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureStone);
}

#pragma region GettersSetters

void ABuilds::setPosX(float posX)
{
    _posX = posX;
    _sprite->setPosition(glm::vec3(_posX, _posY, 0.0f));
}

void ABuilds::setPosY(float posY)
{
    _posY = posY;
    _sprite->setPosition(glm::vec3(_posX, _posY, 0.0f));
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

void ABuilds::setDirection(Direction direction)
{
    _sprite->setDirection(direction * 90);
}

float ABuilds::getPosY() const
{
    return _posY;
}

void ABuilds::setPosXGrid(size_t posX)
{
    posXGrid = posX;
}

void ABuilds::setPosYGrid(size_t posY)
{
    posYGrid = posY;
}

size_t ABuilds::getPosXGrid() const
{
    return posXGrid;
}

Direction ABuilds::getDirection() const
{
    return Direction::UP;
}

size_t ABuilds::getPosYGrid() const
{
    return posYGrid;
}

bool ABuilds::getIsConstructible() const
{
    return _isConstructible;
}

bool ABuilds::getIsBlocking() const
{
    return _isBlocking;
}

void ABuilds::draw(sdf::Renderer &renderer)
{
    _sprite->draw(renderer);
}

bool ABuilds::isUpdatable()
{
    return _updatable;
}

#pragma endregion GettersSetters
