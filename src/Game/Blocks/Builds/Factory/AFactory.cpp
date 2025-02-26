/*
** EPITECH PROJECT, 2025
** AFactory
** File description:
** AFactory
*/

#include "AFactory.hpp"

AFactory::AFactory()
{
    _MaxIn = 50;
    _MaxOut = 50;
}

static int getNbItem(std::vector<Item> items, std::string name)
{
    int i = 0;

    for (Item &it: items) {
        if (it.getName() == name)
            i++;
    }
    return i;
}

bool AFactory::isRecetteCraftable(Recette recette)
{
    for (Item &it: recette._Ins) {
        if (getNbItem(_Ins, it.getName()) < getNbItem(recette._Ins, it.getName()))
            return false;
    }
    return true;
}

bool AFactory::craftRecette(Recette recette)
{
    if (isRecetteCraftable(recette) == false)
        return false;
    for (Item &it: recette._Ins) {
        for (size_t i = 0; i < _Ins.size(); i++) {
            if (_Ins[i].getName() == it.getName()) {
                _Ins.erase(_Ins.begin() + i);
                break;
            }
        }
    }
    for (Item &it: recette._Outs)
        _Outs.push_back(it);
    return true;
}
