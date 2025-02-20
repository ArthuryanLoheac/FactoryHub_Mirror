/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** map_grid
*/

#pragma once
#include <vector>
#include <stdexcept>
#include <memory>

class IBlock;

class MapGrid
{
    public:
        MapGrid(size_t X, size_t Y);
        std::unique_ptr<IBlock> &GetIBlockAtPos(size_t X, size_t Y, size_t Z);
        std::vector<std::unique_ptr<IBlock>> &getAllBlocksAtPos(size_t X, size_t Y);
        void AddBlock(std::unique_ptr<IBlock> block, size_t X, size_t Y);
        void DeleteBlock(size_t X, size_t Y, size_t Z);

    private:
        std::vector<std::vector<std::vector<
            std::unique_ptr<IBlock>>>> _grid;
        size_t _sizeX;
        size_t _sizeY;
};
