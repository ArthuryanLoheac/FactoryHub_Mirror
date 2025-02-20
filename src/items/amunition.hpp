#pragma once
#include <vector>
#include "item.hpp"

class AAmunition : public IItem
{
    protected:
        AAmunition();
    private:
        size_t _tier;
    public:
        size_t getTier() const;
};