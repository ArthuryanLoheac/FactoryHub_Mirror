/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Base
*/

#include "Base.hpp"

Base::Base()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f),
        sdf::GetterTextures::instance->getTexture("Base"), 0.0f);
    _AllItemAccepted = true;
    _noMax = true;
    setHp(1000);
}

bool Base::addElement(Item item)
{
    if (_items.find(item.getName()) == _items.end())
        _items[item.getName()] = 0;
    _items[item.getName()] += 1;
    return true;
}
