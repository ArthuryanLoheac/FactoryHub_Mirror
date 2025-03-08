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
#include "Stone.hpp"

template <class T>
void generate(MapGrid &map, float density = 0.2f)
{
    initBruit2D(map.getSizeX(), map.getSizeY(), 8, 6);

    for (size_t i = 0; i < map.getSizeX(); i++) {
        for (size_t j = 0; j < map.getSizeY(); j++) {
            double value = bruit_coherent2D(i, j, 0.5);
            if (value < density && map.getAllBlocksAtPos(i, j).empty())
                map.addBlock(std::make_shared<T>(T()), i, j);
        }
    }
    destroyBruit2D();
}

void generateAll(MapGrid &map)
{
    map.addBorder();
    generate<Stone>(map, 0.35f);
    generate<Zinc>(map);
    generate<Cuivre>(map);
    generate<Eau>(map, 0.3f);
    generate<Acier>(map);
    generate<Charbon>(map);
    generate<Salpetre>(map);
    generate<Uranium>(map);
}
