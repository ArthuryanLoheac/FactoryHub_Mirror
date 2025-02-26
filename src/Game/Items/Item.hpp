/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** IItem
*/

#pragma once
#include <string>

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
    
    private:
        std::string _name;
        typeItem _type;
        int _tier;
};
