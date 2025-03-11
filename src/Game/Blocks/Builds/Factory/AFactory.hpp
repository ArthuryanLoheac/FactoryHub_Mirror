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
                Recette(std::vector<Item> Ins, std::vector<Item> Outs, float timeProd);
        };
    protected:
        std::vector<Recette> _Recettes;
        float _timeProd;
        std::shared_ptr<Recette> _prod;
    
        AFactory();
        bool isRecetteCraftable(Recette recette);
        bool craftRecette(Recette recette);
        void checkCraftNewReceipe();
        bool addProdLastReceipe();
        void update(float deltaTime, MapGrid map) override;
};
