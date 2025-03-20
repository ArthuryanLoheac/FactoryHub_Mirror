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
    _updatable = true;
    _items["SteelRaw"] = 100;
    _items["CopperRaw"] = 100;
    setHp(1000);
}

void Base::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
    // List all items in base for debug

    //printf("===== Base =====\n");
    //for (auto &item : _items)
    //    printf("%s: %d\n", item.first.c_str(), item.second);
}

bool Base::addElement(Item item)
{
    if (_items.find(item.getName()) == _items.end())
        _items[item.getName()] = 0;
    _items[item.getName()] += 1;
    return true;
}
