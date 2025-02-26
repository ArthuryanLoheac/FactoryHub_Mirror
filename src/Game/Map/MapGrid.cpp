/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** map_grid
*/

#include "MapGrid.hpp"

#include "Zinc.hpp"
#include "Cuivre.hpp"
#include "Charbon.hpp"
#include "Acier.hpp"
#include "Salpetre.hpp"
#include "Uranium.hpp"
#include "Eau.hpp"
#include "Stone.hpp"

MapGrid::MapGrid(size_t X, size_t Y)
{
    initEmptyMap(X, Y);
    _sizeX = X;
    _sizeY = Y;
}

std::shared_ptr<IBlock> MapGrid::GetIBlockAtPos(size_t X, size_t Y, size_t Z)
{
    if (X >= _sizeX || Y >= _sizeY || Z >= _grid[X][Y].size())
        throw std::out_of_range("Out of range");
    return _grid[X][Y][Z];
}

std::vector<std::shared_ptr<IBlock>> MapGrid::getAllBlocksAtPos(size_t X, size_t Y)
{
    if (X >= _sizeX || Y >= _sizeY)
        throw std::out_of_range("Out of range");
    return _grid[X][Y];
}

void MapGrid::addBlock(std::shared_ptr<IBlock> block, size_t X, size_t Y)
{
    if (X >= _sizeX || Y >= _sizeY)
        throw std::out_of_range("Out of range");
    _grid[X][Y].push_back(block);
}

void MapGrid::addBorder(void)
{
    for (size_t i = 0; i < this->getSizeX(); i++) {
        for (size_t j = 0; j < this->getSizeY(); j++) {
            if (i == 0 || i == this->getSizeX() - 1 ||
                j == 0 || j == this->getSizeY() - 1)
                this->addBlock(std::make_shared<Stone>(Stone()), i, j);
            if (i == 1 || i == this->getSizeX() - 2 ||
                j == 1 || j == this->getSizeY() - 2)
                if (((rand() % 3) + 1) == 3)
                    this->addBlock(std::make_shared<Stone>(Stone()), i, j);
        }
    }
}

void MapGrid::deleteBlock(size_t X, size_t Y, size_t Z)
{
    if (X >= _sizeX || Y >= _sizeY || Z >= _grid[X][Y].size())
        throw std::out_of_range("Out of range");
    _grid[X][Y].erase(_grid[X][Y].begin() + Z);
}

void MapGrid::initEmptyMap(size_t X, size_t Y)
{
    for (size_t i = 0; i < X; i++) {
        std::vector<std::vector<std::shared_ptr<IBlock>>> tmp;
        for (size_t j = 0; j < Y; j++) {
            std::vector<std::shared_ptr<IBlock>> tmp2;
            tmp.push_back(tmp2);
        }
        _grid.push_back(tmp);
    }
}

std::ostream &operator<<(std::ostream &os, MapGrid &mapGrid)
{
    for (size_t x = 0; x < mapGrid.getSizeX(); x++) {
        for (size_t y = 0; y < mapGrid.getSizeY(); y++) {
            if (mapGrid.getAllBlocksAtPos(x, y).size() == 0)
                os << " ";
            else {
                if (dynamic_cast<Zinc *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "Z";
                else if (dynamic_cast<Cuivre *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "C";
                else if (dynamic_cast<Charbon *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "O";
                else if (dynamic_cast<Acier *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "A";
                else if (dynamic_cast<Salpetre *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "S";
                else if (dynamic_cast<Uranium *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "U";
                else if (dynamic_cast<Eau *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "E";
                else if (dynamic_cast<Stone *>(mapGrid.GetIBlockAtPos(x, y, 0).get())) os << "R";
                else os << "X";
            }
        }
        os << "|" << std::endl;
    }
    return os;
}
