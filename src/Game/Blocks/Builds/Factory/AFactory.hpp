/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AFactory
*/

#pragma once
#include "ABuilds.hpp"

class AFactory : public ABuilds
{
    public:
        class Recette {
            public:
                std::vector<Item> _Ins;
                std::vector<Item> _Outs;
                float _timeProd;
        };
    protected:
        std::vector<Recette> _Recettes;
    
        AFactory();
        bool isRecetteCraftable(Recette recette);
        bool craftRecette(Recette recette);
};
