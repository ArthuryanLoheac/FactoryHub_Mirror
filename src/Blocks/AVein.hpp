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
        std::shared_ptr<IItem> _ressource;
        AVein(std::shared_ptr<IItem> item);
};
