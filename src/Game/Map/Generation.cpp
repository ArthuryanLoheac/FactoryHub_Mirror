/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Generation
*/
#include "MapGrid.hpp"
#include "Perlin.hpp"

#include "Zinc.hpp"
#include "Cuivre.hpp"
#include "Charbon.hpp"
#include "Acier.hpp"
#include "Salpetre.hpp"
#include "Uranium.hpp"
#include "Eau.hpp"

template <class T>
void generateZinc(MapGrid &map)
{
    initBruit2D(map.getSizeX(), map.getSizeY(), 8, 6);

    for (size_t i = 0; i < map.getSizeX(); i++) {
        for (size_t j = 0; j < map.getSizeY(); j++) {
            double value = bruit_coherent2D(i, j, 0.5);
            if (value < 0.2 && map.getAllBlocksAtPos(i, j).empty())
                map.addBlock(std::make_shared<T>(T()), i, j);
        }
    }
    destroyBruit2D();
}

void generateAll(MapGrid &map)
{
    generateZinc<Zinc>(map);
    generateZinc<Cuivre>(map);
    generateZinc<Eau>(map);
    generateZinc<Acier>(map);
    generateZinc<Charbon>(map);
    generateZinc<Salpetre>(map);
    generateZinc<Uranium>(map);
}