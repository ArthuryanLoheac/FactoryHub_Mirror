#pragma once
#include <vector>

class IBlock;

class MapGrid
{
    public:
        MapGrid(size_t X, size_t Y);
        IBlock GetIBlockAtPos(size_t X, size_t Y);
        void AddBlock(class Iblock block, size_t X, size_t Y);
        void DeleteBlock(size_t X, size_t Y, size_t Z);

        private:
        std::vector<std::vector<std::vector<IBlock>>> _grid;
        size_t _sizeX;
        size_t _sizeY;
};