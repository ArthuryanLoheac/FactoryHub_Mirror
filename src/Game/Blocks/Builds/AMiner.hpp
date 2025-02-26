/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AMiner
*/

#pragma once
#include "ABuilds.hpp"
#include "Item.hpp"

class AMiner : public ABuilds
{
    public:
        void update(float deltaTime) override;
        void setMiningItem(Item new_item);

    protected:
        AMiner();
        float _speedMining;
        float _clockMining = 0;
        Item _MiningItem;
};