/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Base
*/

#include "Base.hpp"

Base::Base()
{
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 30.0f),
        sdf::GetterTextures::instance->getTexture("Base"), 0.0f);
    _AllItemAccepted = true;
    _noMax = true;
    _updatable = true;
    _items["SteelRaw"] = 100;
    _items["CopperRaw"] = 100;
    //  DEVTOOL, START WITH ALL THE MATERIAL
    //_items["SteelRaw"] = 10000;
    //_items["CopperRaw"] = 10000;
    //_items["CoalRaw"] = 10000;
    //_items["Steel_BAR"] = 10000;
    //_items["SaltpeterRaw"] = 10000;
    //_items["ZincRaw"] = 10000;
    //_items["Copper_Wire"] = 10000;
    //_items["Energy_Capacitor"] = 10000;
    //_items["UraniumRaw"] = 10000;
    //_items["Reinforced_Socket"] = 10000;
    //_items["Zinc_Plate"] = 10000;
    //_items["Rubber"] = 10000;
    //_items["WaterRaw"] = 10000;
    //_items["Reinforced_Brass"] = 10000;
    //_items["Copper_Balls"] = 10000;
    //_items["Black_Powder"] = 10000;
    //_items["Gunpowder"] = 10000;
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
