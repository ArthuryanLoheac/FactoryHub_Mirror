/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** AMiner
*/
#include "AMiner.hpp"
#include "ABuilds.hpp"

AMiner::AMiner() : ABuilds()
{
    _MaxIn = 0;
    _MaxOut = 100;
}

MinerT1::MinerT1() : AMiner()
{
    _speedMining = 0.5;
}

void AMiner::update(float deltaTime, MapGrid map)
{
    (void)map;
    _clockMining += deltaTime;
    if (_clockMining >= _speedMining) {
        _Outs.push_back(_MiningItem);
        _clockMining -= -_speedMining;
    }
}

void AMiner::setMiningItem(Item new_item)
{
    _MiningItem = new_item;
}

