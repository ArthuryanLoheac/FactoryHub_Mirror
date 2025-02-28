/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AMiner
*/
#include "AMiner.hpp"
#include "ABuilds.hpp"
#include "AVein.hpp"

AMiner::AMiner() : ABuilds()
{
    _MaxIn = 0;
    _MaxOut = 100;
}

void AMiner::update(float deltaTime, MapGrid map)
{
    _clockMining += deltaTime;
    if (_clockMining >= _speedMining) {
        int x = getPosX();
        int y = getPosY();
        std::shared_ptr<IBlock> block = map.GetIBlockAtPos(x, y, 0);
        std::shared_ptr<AVein> vein = std::dynamic_pointer_cast<AVein>(block);
        if (vein) {
            setMiningItem(vein->getRessource());
        }
        _Outs.push_back(_MiningItem);
        _clockMining -= _speedMining;
    }
}

void AMiner::setMiningItem(Item new_item)
{
    _MiningItem = new_item;
}

