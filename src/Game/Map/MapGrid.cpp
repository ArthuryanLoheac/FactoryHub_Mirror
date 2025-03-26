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
#include "ATapis.hpp"
#include "AMiner.hpp"
#include <Base.hpp>

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

void MapGrid::addBlock(std::shared_ptr<IBlock> block, size_t X, size_t Y, Direction direction)
{
    if (X >= _sizeX || Y >= _sizeY)
        throw std::out_of_range("Out of range");
    block->setPosX(X);
    block->setPosY(Y);
    block->setPosXGrid(X);
    block->setPosYGrid(Y);
    block->setDirection(direction);
    _grid[X][Y].push_back(block);
    if (block.get()->isUpdatable())
        _blocksUpdated.push_back(block);
    if (base != nullptr && dynamic_cast<Base *>(block.get()) != nullptr)
        base = dynamic_cast<Base *>(block.get());
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
    _grid[X][Y][Z]->setDestroy();
    _grid[X][Y].erase(_grid[X][Y].begin() + Z);
    for (int i = 0; i < _blocksUpdated.size(); i++) {
        if (_blocksUpdated[i].get()->getDestroy() == true){
            _blocksUpdated.erase(_blocksUpdated.begin() + i);
            return;
        }
    }
}

void MapGrid::draw(sdf::Renderer &renderer)
{
    for (size_t i = 0; i < _sizeX; i++) {
        for (size_t j = 0; j < _sizeY; j++) {
            for (size_t k = 0; k < _grid[i][j].size(); k++) {
                _grid[i][j][_grid[i][j].size() - 1 - k]->draw(renderer);
            }
        }
    }
}

void MapGrid::update(float deltaTime)
{
    for (size_t i = 0; i < _blocksUpdated.size(); i++)
        _blocksUpdated[i]->update(deltaTime, *this);
}

IBlock *MapGrid::getBase()
{
    return base;
}

void MapGrid::clear()
{
    for (size_t i = 0; i < _sizeX; i++) {
        for (size_t j = 0; j < _sizeY; j++) {
            _grid[i][j].clear();
        }
    }
    _blocksUpdated.clear();
    base = nullptr;
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
