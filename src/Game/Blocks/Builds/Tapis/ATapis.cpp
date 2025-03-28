/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ATapis
*/

#include "ATapis.hpp"

bool ATapis::addElement(Item item)
{
    return addElementTapis(item, _direction);
}

void ATapis::setDirection(Direction direction)
{
    _direction = direction;
    _sprite->setDirection(direction * 90);
}

bool ATapis::myAddElement(Item item, Direction direction)
{
    if (_AllItemAccepted) {
        std::tuple<float, Item, Direction> tuple = std::make_tuple(0.0f, item, direction);
        if (_itemsTransitting.size() > 0 &&
            std::get<0>(_itemsTransitting[_itemsTransitting.size() - 1]) < _deltaMinPercent)
            return false;
        _itemsTransitting.push_back(tuple);
        return true;
    }
    for (Item &it : _AcceptedItems) {
        if (it.getName() == item.getName()) {
            _itemsTransitting.push_back(std::make_tuple(0.0f, item, direction));
            return true;
        }
    }
    return false;
}

bool ATapis::addElementTapis(Item item, Direction direction)
{
    if (_itemsTransitting.size() > 0 &&
        std::get<0>(_itemsTransitting[_itemsTransitting.size() - 1]) >= _deltaMinPercent)
        return myAddElement(item, direction);
    else if (_itemsTransitting.size() == 0)
        return myAddElement(item, direction);
    return false;
}

static bool outElementToTapis(ATapis *tapis,
    std::vector<std::tuple<float, Item, Direction>> &_itemsTransitting, Direction direction)
{
    if (tapis->addElementTapis(std::get<1>(_itemsTransitting[0]), direction)) {
        _itemsTransitting.erase(_itemsTransitting.begin());
        return true;
    }
    return false;
}

static bool outElementToABuilds(ABuilds *block,
    std::vector<std::tuple<float, Item, Direction>> &_itemsTransitting)
{
    if (block->addElement(std::get<1>(_itemsTransitting[0]))) {
        _itemsTransitting.erase(_itemsTransitting.begin());
        return true;
    }
    return false;
}

static std::vector<std::shared_ptr<IBlock>> getIBlockAtModPos(MapGrid map, int X, int Y, Direction direction)
{
    if (direction == Direction::UP)
        return map.getAllBlocksAtPos(X, Y + 1);
    if (direction == Direction::DOWN)
        return map.getAllBlocksAtPos(X, Y - 1);
    if (direction == Direction::LEFT)
        return map.getAllBlocksAtPos(X - 1, Y);
    if (direction == Direction::RIGHT)
        return map.getAllBlocksAtPos(X + 1, Y);
    throw std::out_of_range("Direction not found");
}

static Direction getOppositeDirection(Direction direction)
{
    if (direction == Direction::UP)
        return Direction::DOWN;
    if (direction == Direction::DOWN)
        return Direction::UP;
    if (direction == Direction::LEFT)
        return Direction::RIGHT;
    if (direction == Direction::RIGHT)
        return Direction::LEFT;
    throw std::out_of_range("Direction not found");
}

void ATapis::update(float deltaTime, MapGrid map)
{
    nbUpdate++;
    if (nbUpdate > 10) {
        nbUpdate = 0;
        updateTakeBehind(map);
        updateAllItemsTransitting(deltaTime);
        updatePushItemFront(map);
        updatePosSprite();
    } else {
        updateAllItemsTransitting(deltaTime);
        updatePosSprite();
    }
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
    ATapis *tapis;
    std::vector<std::shared_ptr<IBlock>> blocksBehind;

    for (size_t i = 0; i < _itemsTransitting.size(); i++) {
        if (std::get<0>(_itemsTransitting[i]) < 1.f)
            continue;
        blocksBehind = getIBlockAtModPos(map, posXGrid, posYGrid, _direction);
        if (blocksBehind.size() == 0) return;
        block = dynamic_cast<ABuilds *>(blocksBehind[blocksBehind.size() - 1].get());
        if (block == nullptr) return;
        tapis = dynamic_cast<ATapis *>(block);
        if (tapis != nullptr) {
            if (tapis->getDirection() == (_direction + 2) % 4)
                return;
            if (tapis->myAddElement(std::get<1>(_itemsTransitting[i]), _direction))
                _itemsTransitting.erase(_itemsTransitting.begin() + i);
        } else {
            if (block->addElement(std::get<1>(_itemsTransitting[i])) == true)
                _itemsTransitting.erase(_itemsTransitting.begin() + i);
        }
    }
}

void ATapis::updatePosSpriteFirst(size_t i)
{
    if (std::get<2>(_itemsTransitting[i]) == UP)
        std::get<1>(_itemsTransitting[i]).setPos(_posX, _posY - 0.5f + std::get<0>(_itemsTransitting[i])); 
    if (std::get<2>(_itemsTransitting[i]) == DOWN)
        std::get<1>(_itemsTransitting[i]).setPos(_posX, _posY + 0.5f - std::get<0>(_itemsTransitting[i]));
    if (std::get<2>(_itemsTransitting[i]) == RIGHT)
        std::get<1>(_itemsTransitting[i]).setPos(_posX - 0.5f + std::get<0>(_itemsTransitting[i]), _posY);
    if (std::get<2>(_itemsTransitting[i]) == LEFT)
        std::get<1>(_itemsTransitting[i]).setPos(_posX + 0.5f - std::get<0>(_itemsTransitting[i]), _posY);
}

void ATapis::updatePosSpriteSecond(size_t i)
{
    if (_direction == UP)
        std::get<1>(_itemsTransitting[i]).setPos(_posX, _posY - 0.5f + std::get<0>(_itemsTransitting[i])); 
    if (_direction == DOWN)
        std::get<1>(_itemsTransitting[i]).setPos(_posX, _posY + 0.5f - std::get<0>(_itemsTransitting[i]));
    if (_direction == RIGHT)
        std::get<1>(_itemsTransitting[i]).setPos(_posX - 0.5f + std::get<0>(_itemsTransitting[i]), _posY);
    if (_direction == LEFT)
        std::get<1>(_itemsTransitting[i]).setPos(_posX + 0.5f - std::get<0>(_itemsTransitting[i]), _posY);
}


void ATapis::updatePosSprite()
{
    for (size_t i = 0; i < _itemsTransitting.size(); i++) {
        if (std::get<0>(_itemsTransitting[i]) < 0.5f)
            updatePosSpriteFirst(i);
        else
            updatePosSpriteSecond(i);
    }
}

void ATapis::draw(sdf::Renderer &renderer)
{
    if (_direction == UP || _direction == RIGHT) {
        for (int i = _itemsTransitting.size() - 1; i >= 0; i--) {
            std::get<1>(_itemsTransitting[i]).draw(renderer);
        }
    }
    if (_direction == DOWN || _direction == LEFT) {
        for (int i = 0; i < _itemsTransitting.size(); i++)
            std::get<1>(_itemsTransitting[i]).draw(renderer);
    }
    _sprite->draw(renderer);
}

Direction ATapis::getDirection() const
{
    return _direction;
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
    _updatable = true;
    _AllItemAccepted = true;
    _direction = UP;
}
