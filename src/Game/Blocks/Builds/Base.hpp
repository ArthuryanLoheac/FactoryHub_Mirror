/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Base
*/

#pragma once
#include "ABuilds.hpp"

class Base : public ABuilds
{
    public:
        Base();
        void update(float deltaTime, MapGrid map) override;
        bool addElement(Item item) override;
    
    private:
        std::map<std::string, int> _items;
};
