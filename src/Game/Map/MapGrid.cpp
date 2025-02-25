/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** map_grid
*/

#include "MapGrid.hpp"

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
            else
                os << "X";
        }
        os << "|" << std::endl;
    }
    return os;
}
