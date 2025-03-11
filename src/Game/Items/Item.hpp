/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** IItem
*/

#pragma once
#include <string>
#include "Sprite.hpp"
#include "GetterTextures.hpp"

class Item
{
    public:
        enum typeItem {
            AMUNITION,
            RESSOURCE,
            OTHER
        };

        Item(typeItem type, std::string name, int tier);
        Item(typeItem type, std::string name);
        Item(std::string name, int tier);
        Item(std::string name);
        Item();
        std::string getName() const;
        typeItem getType() const;
        int getTier() const;
        void setPos(float posX, float posY);
        void draw(sdf::Renderer &renderer);
    
    private:
        std::string _name;
        typeItem _type;
        sdf::Sprite *_sprite;
        int _tier;
};
