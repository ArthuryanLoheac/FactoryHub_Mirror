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
#include <random>
#include "IBlock.hpp"
#include "Texture.hpp"
#include "Sdf.hpp"
#include "Direction.hpp"

class IBlock;

class MapGrid
{
    public:
        MapGrid(size_t X, size_t Y);
        std::shared_ptr<IBlock> GetIBlockAtPos(size_t X, size_t Y, size_t Z);
        std::vector<std::shared_ptr<IBlock>> getAllBlocksAtPos(size_t X, size_t Y);
        void addBlock(std::shared_ptr<IBlock> block, size_t X, size_t Y, Direction direction = Direction::UP);
        void addBorder(void);
        void deleteBlock(size_t X, size_t Y, size_t Z);
        size_t getSizeX() const { return _sizeX; }
        size_t getSizeY() const { return _sizeY; }
        void draw(sdf::Renderer &renderer);
        void update(float deltaTime);
        IBlock *getBase();
        void clear();

    private:
        IBlock *base;
        void initEmptyMap(size_t X, size_t Y);

        std::vector<std::vector<std::vector<
            std::shared_ptr<IBlock>>>> _grid;
        std::vector<std::shared_ptr<IBlock>> _blocksUpdated;
        size_t _sizeX;
        size_t _sizeY;
        sdf::Texture textureStone = sdf::Texture("Assets/Stone.png");
        sdf::Texture textureZinc = sdf::Texture("Assets/Zinc.png");
};
