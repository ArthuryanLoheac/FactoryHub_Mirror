/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** IItem
*/

#include "Item.hpp"

#pragma region Constructors

Item::Item(typeItem type, std::string name, int tier)
{
    _type = type;
    _name = name;
    _tier = tier;
}

Item::Item(typeItem type, std::string name)
{
    _type = type;
    _name = name;
    _tier = -1;
}

Item::Item(std::string name, int tier)
{
    _type = OTHER;
    _name = name;
    _tier = tier;
}

Item::Item(std::string name)
{
    _type = OTHER;
    _name = name;
    _tier = -1;
}

Item::Item()
{
    _type = OTHER;
    _name = "";
    _tier = -1;
}

#pragma endregion Constructors

#pragma region Getters

std::string Item::getName() const
{
    return _name;
}

Item::typeItem Item::getType() const
{
    return _type;
}

int Item::getTier() const
{
    return _tier;
}

#pragma endregion Getters
