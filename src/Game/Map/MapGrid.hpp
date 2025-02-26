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

class IBlock;

class MapGrid
{
    public:
        sdf::Texture textureBg;
        sdf::Texture textureZinc;
        sdf::Texture textureCuivre;
        sdf::Texture textureCharbon;
        sdf::Texture textureAcier;
        sdf::Texture textureSalpetre;
        sdf::Texture textureUranium;
        sdf::Texture textureEau;
        sdf::Texture textureStone;

        MapGrid(size_t X, size_t Y);
        std::shared_ptr<IBlock> GetIBlockAtPos(size_t X, size_t Y, size_t Z);
        std::vector<std::shared_ptr<IBlock>> getAllBlocksAtPos(size_t X, size_t Y);
        void addBlock(std::shared_ptr<IBlock> block, size_t X, size_t Y);
        void addBorder(void);
        void deleteBlock(size_t X, size_t Y, size_t Z);
        size_t getSizeX() const { return _sizeX; }
        size_t getSizeY() const { return _sizeY; }

    private:
        void initEmptyMap(size_t X, size_t Y);

        std::vector<std::vector<std::vector<
            std::shared_ptr<IBlock>>>> _grid;
        size_t _sizeX;
        size_t _sizeY;
};

std::ostream& operator<<(std::ostream &os, MapGrid &mapGrid);
