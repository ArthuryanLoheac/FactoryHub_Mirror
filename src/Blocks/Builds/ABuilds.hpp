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
        std::vector<std::string> _AcceptedItems;
        bool _AllItemAccepted;
        std::vector<std::shared_ptr<IItem>> _Ins;
        std::vector<std::shared_ptr<IItem>> _Outs;
        size_t _MaxIn;
        size_t _MaxOut;
        bool _noMax;
    public:
        bool addElement(std::shared_ptr<IItem> item);
        bool outElement(std::string name);
    protected:
        ABuilds();
};
