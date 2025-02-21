/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#pragma once
#include "IBlock.hpp"
#include "IItem.hpp"

class ABuilds : public IBlock
{
    private:
        std::vector<IItem> _AcceptedItems;
        bool _AllItemAccepted;
        std::vector<IItem> _Ins;
        std::vector<IItem> _Outs;
        size_t _MaxIn;
        size_t _MaxOut;
        bool _noMax;
    public:
        bool addElement(IItem &item);
        bool outElement(IItem &item);
    protected:
        ABuilds();
};
