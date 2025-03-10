/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATapis
*/

#include "ATapis.hpp"

bool ATapis::addElement(Item item)
{
    return addElementTapis(item);
}

void ATapis::setDirection(Direction direction)
{
    _direction = direction;
    _sprite->setDirection(direction * 90);
}

bool ATapis::myAddElement(Item item)
{
    if (_AllItemAccepted) {
        std::tuple<float, Item, Direction> tuple = std::make_tuple(0.0f, item, _direction);
        _itemsTransitting.push_back(tuple);
        return true;
    }
    for (Item &it : _AcceptedItems) {
        if (it.getName() == item.getName()) {
            _itemsTransitting.push_back(std::make_tuple(0.0f, item, _direction));
            return true;
        }
    }
    return false;
}

bool ATapis::addElementTapis(Item item)
{
    if (_itemsTransitting.size() > 0 &&
        std::get<0>(_itemsTransitting[_itemsTransitting.size() - 1]) >= _deltaMinPercent)
        return myAddElement(item);
    else if (_itemsTransitting.size() == 0)
        return myAddElement(item);
    return false;
}

static bool outElementToTapis(ATapis *tapis,
    std::vector<std::tuple<float, Item, ATapis::Direction>> &_itemsTransitting)
{
    if (tapis->addElementTapis(std::get<1>(_itemsTransitting[0]))) {
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

static std::vector<std::shared_ptr<IBlock>> getIBlockAtModPos(MapGrid map, int X, int Y, ATapis::Direction direction)
{
    if (direction == ATapis::UP)
        return map.getAllBlocksAtPos(X, Y + 1);
    if (direction == ATapis::DOWN)
        return map.getAllBlocksAtPos(X, Y - 1);
    if (direction == ATapis::LEFT)
        return map.getAllBlocksAtPos(X - 1, Y);
    if (direction == ATapis::RIGHT)
        return map.getAllBlocksAtPos(X + 1, Y);
    throw std::out_of_range("Direction not found");
}

static ATapis::Direction getOppositeDirection(ATapis::Direction direction)
{
    if (direction == ATapis::Direction::UP)
        return ATapis::Direction::DOWN;
    if (direction == ATapis::Direction::DOWN)
        return ATapis::Direction::UP;
    if (direction == ATapis::Direction::LEFT)
        return ATapis::Direction::RIGHT;
    if (direction == ATapis::Direction::RIGHT)
        return ATapis::Direction::LEFT;
    throw std::out_of_range("Direction not found");
}

void ATapis::update(float deltaTime, MapGrid map)
{
    printf("%ld ", _itemsTransitting.size());
    updateTakeBehind(map);
    updateAllItemsTransitting(deltaTime);
    updatePushItemFront(map);
}

void ATapis::addElementFromBehind(ABuilds *block)
{
    Item *item;

    item = block->outElement();
    if (item != nullptr)
        _itemsTransitting.push_back(std::make_tuple(0, *item, _direction));
}

static float computeAvancement(float pos, float _travelTime, float deltaTime)
{
    float speedPercent = 1.0f / _travelTime;
    float FrameMove = speedPercent * deltaTime;

    pos += FrameMove;
    if (pos >= 1.0f)
        pos = 1.0f;
    return pos;
}

void ATapis::updateAllItemsTransitting(float deltaTime)
{
    float previousPercent;

    for (size_t i = 0; i < _itemsTransitting.size(); i++) {
        std::get<0>(_itemsTransitting[i]) = computeAvancement(
            std::get<0>(_itemsTransitting[i]), _travelTime, deltaTime);
        if (i == 0)
            continue;
        previousPercent = std::get<0>(_itemsTransitting[i - 1]);
        std::get<0>(_itemsTransitting[i]) =
            std::min(std::get<0>(_itemsTransitting[i]), previousPercent - _deltaMinPercent);
    }
    
}

void ATapis::updatePushItemFront(MapGrid map)
{
    ABuilds *block;
    std::vector<std::shared_ptr<IBlock>> blocksBehind;

    for (size_t i = 0; i < _itemsTransitting.size(); i++) {
        if (std::get<0>(_itemsTransitting[i]) < 1.f)
            continue;
        blocksBehind = getIBlockAtModPos(map, posXGrid, posYGrid, _direction);
        if (blocksBehind.size() == 0) return;
        block = dynamic_cast<ABuilds *>(blocksBehind[blocksBehind.size() - 1].get());
        if (block == nullptr) return;
        if (block->addElement(std::get<1>(_itemsTransitting[i])) == true) {
            _itemsTransitting.erase(_itemsTransitting.begin() + i);
            return;
        }
    }
}

void ATapis::updateTakeBehind(MapGrid map)
{
    ABuilds *block;
    std::vector<std::shared_ptr<IBlock>> blocksBehind;

    // Si ABuilds (sauf tapis) est sur la case derriere lui
    blocksBehind = getIBlockAtModPos(map, posXGrid, posYGrid, getOppositeDirection(_direction));
    if (blocksBehind.size() == 0) return;
    block = dynamic_cast<ABuilds *>(blocksBehind[blocksBehind.size() - 1].get());
    if (dynamic_cast<ATapis *>(block) != nullptr) return;
    if (block == nullptr) return;
    // Try take element
    if (_itemsTransitting.size() == 0)// Si pas d'element en cours de transit
        addElementFromBehind(block);
        // Sinon check si le dernier element est assez loin pour ajouter un autre
    else if (std::get<0>(_itemsTransitting[_itemsTransitting.size() - 1]) >= _deltaMinPercent)
        addElementFromBehind(block);
}

ATapis::ATapis()
{
    _AllItemAccepted = true;
    _direction = UP;
}
