/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#pragma once
#include "IBlock.hpp"
#include "Item.hpp"

class ABuilds : public IBlock
{
    private:
        std::vector<std::string> _AcceptedItems;
        bool _AllItemAccepted;
        std::vector<Item> _Ins;
        std::vector<Item> _Outs;
        size_t _MaxIn;
        size_t _MaxOut;
        bool _noMax;
    public:
        bool addElement(Item item);
        bool outElement(std::string name);
    protected:
        ABuilds();
};
