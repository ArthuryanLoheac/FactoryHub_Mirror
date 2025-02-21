/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AAmunition
*/

#pragma once
#include <vector>
#include "IItem.hpp"

class AAmunition : public IItem
{
    protected:
        AAmunition(std::string name);
    private:
        size_t _tier;
    public:
        size_t getTier() const;
};
