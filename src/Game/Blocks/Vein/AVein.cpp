/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AVein
*/

#include "AVein.hpp"

AVein::AVein(Item item)
    : _ressource(item)
{
    _isConstructible = true;
    _isBlocking = false;
    sdf::Texture textureStone = sdf::Texture("Assets/Stone.png");
    _sprite = new sdf::Sprite(glm::vec3(0.0f, 0.0f, 0.0f), textureStone);
    _updatable = false;
}

Item AVein::getRessource() const
{
    return _ressource;
}

void AVein::setPosX(float posX)
{
    _posX = posX;
    _sprite->setPosition(glm::vec3(_posX, _posY, 0.0f));
}

void AVein::setPosY(float posY)
{
    _posY = posY;
    _sprite->setPosition(glm::vec3(_posX, _posY, 0.0f));
}

float AVein::getPosX() const
{
    return _posX;
}

float AVein::getPosY() const
{
    return _posY;
}

void AVein::setPosXGrid(size_t posX)
{
    posXGrid = posX;
}

void AVein::setPosYGrid(size_t posY)
{
    posYGrid = posY;
}

void AVein::setDirection(Direction direction)
{
    _sprite->setDirection(direction * 90);
}

Direction AVein::getDirection() const
{
    return Direction::UP;
}

size_t AVein::getPosXGrid() const
{
    return posXGrid;
}

size_t AVein::getPosYGrid() const
{
    return posYGrid;
}


bool AVein::getIsConstructible() const
{
    return _isConstructible;
}

bool AVein::getIsBlocking() const
{
    return _isBlocking;
}

void AVein::update(float deltaTime, MapGrid map)
{
    (void)deltaTime;
    (void)map;
}

void AVein::draw(sdf::Renderer &renderer)
{
    _sprite->draw(renderer);
}

bool AVein::isUpdatable()
{
    return _updatable;
}