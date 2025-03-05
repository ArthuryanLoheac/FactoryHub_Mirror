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
        bool addElement(Item item) override;
        void setDirection(Direction direction);
        bool addElementTapis(Item item);
        bool outElementTapis(std::string name, MapGrid map);
        void update(float deltaTime, MapGrid map) override;
        void updateTakeBehind(MapGrid map);
        void addElementFromBehind(ABuilds *block);
        void updateAllItemsTransitting(float deltaTime);
        void updatePushItemFront(MapGrid map);
        void updatePosSprite();
        void draw(sdf::Renderer &renderer) override;
    protected:
        ATapis();
        std::vector<std::tuple<float, Item, Direction>> _itemsTransitting;
        Direction _direction;
        float _deltaMinPercent; // 0.10f = 10 objects max on tapis (1 each 10%)
        float _travelTime; // duree pour un objet de parcourir le tapis
    private:
        bool myAddElement(Item item);
};
