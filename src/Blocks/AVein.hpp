/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#pragma once
#include "IBlock.hpp"
#include "Item.hpp"

class AVein : public IBlock
{
    protected:
        Item _ressource;
        AVein(Item item);
};
