/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATapis
*/

#pragma once
#include "ABuilds.hpp"
#include "MapGrid.hpp"

class ATapis : public ABuilds
{
    public:
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        void setDirection(Direction direction);
        bool addElementTapis(Item item, Direction direction);
        bool outElementTapis(std::string name, MapGrid map);
        void update(float deltaTime, MapGrid map) override;
    protected:
        ATapis();
        std::vector<std::tuple<float, Item, Direction>> _itemsTransitting;
        Direction _direction;
        float _speedPercent; // 0.10f = 10 objects max on tapis (1 each 10%)
};
