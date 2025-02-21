/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ARessource
*/

#pragma once
#include "IItem.hpp"

class ARessource : public IItem
{
    private:
        std::string _name;
    protected:
        ARessource(std::string name);
        std::string getName() const override;
};