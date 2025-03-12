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
    return true;
}

void AFactory::checkCraftNewReceipe()
{
    for (Recette &recette: _Recettes) {
        if (isRecetteCraftable(recette) == true) {
            if (craftRecette(recette) == true) {
                _timeProd = recette._timeProd;
                _prod = std::make_shared<Recette>(recette);
                break;
            }
        }
    }
}

bool AFactory::addProdLastReceipe()
{
    if (_prod.get() != nullptr) {
        if (_Outs.size() + _prod.get()->_Outs.size() <= _MaxOut) {
            for (Item &it : _prod.get()->_Outs){
                Item cpy = Item(it.getName());
                _Outs.push_back(cpy);
            }
        } else
            return false;
    }
    return true;
}

void AFactory::update(float deltaTime, MapGrid map)
{
    if (_timeProd > 0) {
        _timeProd -= deltaTime;
        return;
    }
    if (addProdLastReceipe() == false)
        return;
    checkCraftNewReceipe();
}


AFactory::Recette::Recette(std::vector<Item> Ins, std::vector<Item> Outs, float timeProd)
{
    _Ins = Ins;
    _Outs = Outs;
    _timeProd = timeProd;
}
