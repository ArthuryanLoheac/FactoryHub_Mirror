/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#include "AVein.hpp"

AVein::AVein(std::shared_ptr<IItem> item)
    : _ressource(item)
{
    _isConstructible = true;
    _isBlocking = false;
}