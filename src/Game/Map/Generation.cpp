/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** Generation
*/
#include "MapGrid.hpp"
#include "Zinc.hpp"
#include "Perlin.hpp"

void generateAll(MapGrid &map)
{
    initBruit2D(map.getSizeX(), map.getSizeY(), 8, 6);

    for (size_t i = 0; i < map.getSizeX(); i++) {
        for (size_t j = 0; j < map.getSizeY(); j++) {
            double value = bruit_coherent2D(i, j, 0.5);
            if (value < 0.25) {
                map.addBlock(std::make_shared<Zinc>(Zinc()), i, j);
            }
        }
    }
    destroyBruit2D();
}