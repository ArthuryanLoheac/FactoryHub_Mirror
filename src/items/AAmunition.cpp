/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AAmunition
*/

#include "AAmunition.hpp"

AAmunition::AAmunition(std::string name)
{
    _name = name;
}

size_t AAmunition::getTier() const
{
    return _tier;
}