/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#include "ABuilds.hpp"

bool ABuilds::addElement(Item item)
{
    if (_noMax == false && _Ins.size() >= _MaxIn)
        return false;
    if (_AllItemAccepted == false) {
        for (std::string str: _AcceptedItems) {
            if (str == item->getName()) {
                _Ins.push_back(item);
                return true;
            }
        }
        return false;
    }
    _Ins.push_back(item);
    return true;
}

bool ABuilds::outElement(std::string name)
{
    int i = 0;

    for (Item &it: _Ins) {
        if (it->getName() == name) {
            _Outs.erase(_Outs.begin() + i);
            return true;
        }
        i++;
    }
    return false;
}

ABuilds::ABuilds()
{
    _AllItemAccepted = false;
    _noMax = false;
    _isConstructible = false;
    _isBlocking = true;
}
