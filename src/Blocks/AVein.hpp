/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#pragma once
#include "IBlock.hpp"
#include "IItem.hpp"

class AVein : public IBlock
{
    protected:
        IItem _ressource;
        AVein(IItem item);
};
