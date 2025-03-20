/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** IItem
*/

#include "Item.hpp"

#pragma region Constructors

Item::Item(typeItem type, std::string name, int tier)
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 20),
        sdf::GetterTextures::instance->getTexture(name));
    _type = type;
    _name = name;
    _tier = tier;
}

Item::Item(typeItem type, std::string name)
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 20),
        sdf::GetterTextures::instance->getTexture(name));
    _type = type;
    _name = name;
    _tier = -1;
}

Item::Item(std::string name, int tier)
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 20),
        sdf::GetterTextures::instance->getTexture(name));
    _type = OTHER;
    _name = name;
    _tier = tier;
}

Item::Item(std::string name)
{
    _sprite = new sdf::Sprite(glm::vec3(0, 0, 20),
        sdf::GetterTextures::instance->getTexture(name));
    _type = OTHER;
    _name = name;
    _tier = -1;
}

Item::Item()
{
    _sprite = nullptr;
    _type = OTHER;
    _name = "";
    _tier = -1;
}

#pragma endregion Constructors

#pragma region Getters

std::string Item::getName() const
{
    return _name;
}

Item::typeItem Item::getType() const
{
    return _type;
}

int Item::getTier() const
{
    return _tier;
}

void Item::setPos(float posX, float posY)
{
    _sprite->setPosition(glm::vec2(posX, posY));
    _sprite->setDirection(0);
}

void Item::setLayer(float layer)
{
    _sprite->setLayer(layer);
}

void Item::draw(sdf::Renderer &renderer)
{
    _sprite->draw(renderer);
}


#pragma endregion Getters
