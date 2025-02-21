/*
** EPITECH PROJECT, 2025
** FactoryHub
** File description:
** ABuilds
*/

#include "ABuilds.hpp"

bool ABuilds::addElement(IItem &item)
{
    if (_noMax == false && _Ins.size() >= _MaxIn)
        return false;
    if (_AllItemAccepted == false) {
        for (IItem &it: _AcceptedItems) {
            if (it.getName() == item.getName()) {
                _Ins.push_back(item);
                return true;
            }
        }
        return false;
    }
}

bool ABuilds::outElement(IItem &item)
{
    int i = 0;

    for (IItem &it: _Ins) {
        if (it.getName() == item.getName()) {
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
