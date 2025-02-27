/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATapis
*/

#include "ATapis.hpp"

void ATapis::setDirection(Direction direction)
{
    _direction = direction;
    _sprite->setDirection(direction * 90);
}

bool ATapis::addElementTapis(Item item, Direction direction)
{
    if (_itemsTransitting.size() > 0 &&
        std::get<0>(_itemsTransitting[_itemsTransitting.size() - 1]) >= _speedPercent) {
        if (_AllItemAccepted) {
            _itemsTransitting.push_back(std::make_tuple(0, item, direction));
            return true;
        }
        for (Item &it : _AcceptedItems) {
            if (it.getName() == item.getName()) {
                _itemsTransitting.push_back(std::make_tuple(0, item, direction));
                return true;
            }
        }
    }
    return false;
}

static bool outElementToTapis(ATapis *tapis,
    std::vector<std::tuple<float, Item, ATapis::Direction>> &_itemsTransitting)
{
    if (tapis->addElementTapis(std::get<1>(_itemsTransitting[0]), std::get<2>(_itemsTransitting[0]))) {
        _itemsTransitting.erase(_itemsTransitting.begin());
        return true;
    }
    return false;
}

static bool outElementToABuilds(ABuilds *block,
    std::vector<std::tuple<float, Item, ATapis::Direction>> &_itemsTransitting)
{
    if (block->addElement(std::get<1>(_itemsTransitting[0]))) {
        _itemsTransitting.erase(_itemsTransitting.begin());
        return true;
    }
    return false;
}

bool ATapis::outElementTapis(std::string name, MapGrid map)
{
    int newPosX = _posX + (_direction == RIGHT ? 1 : (_direction == LEFT ? -1 : 0));
    int newPosY = _posY + (_direction == DOWN ? 1 : (_direction == UP ? -1 : 0));
    std::vector<std::shared_ptr<IBlock>> blocks;
    ABuilds *block;
    ATapis *tapis;

    try {
        blocks = map.getAllBlocksAtPos(newPosX, newPosY);
        if (blocks.size() == 0)
            return false;
        tapis = dynamic_cast<ATapis *>(blocks[blocks.size() - 1].get());
        if (tapis != nullptr)
            return outElementToTapis(tapis, _itemsTransitting);
        block = dynamic_cast<ABuilds *>(blocks[blocks.size() - 1].get());
        if (block != nullptr)
            return outElementToABuilds(block, _itemsTransitting);
        return false;
    } catch (std::out_of_range &e) {
        return false;
    }
}

void ATapis::update(float deltaTime, MapGrid map)
{
    // Update items transitting on tapis
    for (std::tuple<float, Item, Direction> &item : _itemsTransitting) {
        std::get<0>(item) += deltaTime * _speedPercent;
        if (std::get<0>(item) >= 1) {
            outElementTapis(std::get<1>(item).getName(), map);
        }
    }
    // Scan for items to Extract (All but _direction)
    // si pourcentage du dernier element du _itemsTransitting
        // est > _speedPercent alors on peut sortir un item
    // si item dans _outs du block a cote alors on le sort et le met sur le tapis avec AddElementTapis
}

ATapis::ATapis()
{
    _AllItemAccepted = true;
    _direction = UP;
}