/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ARessource
*/

#include "ARessource.hpp"

ARessource::ARessource(std::string name)
{
    _name = name;
}

std::string ARessource::getName() const
{
    return _name;
}