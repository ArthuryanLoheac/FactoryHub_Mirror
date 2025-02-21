/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** IItem
*/

#pragma once
#include <string>

class IItem
{
    public:
        IItem() = default;
        virtual std::string getName() const = 0;
    protected:
        std::string _name;
};
