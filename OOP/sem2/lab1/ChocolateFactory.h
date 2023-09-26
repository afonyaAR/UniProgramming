#pragma once
#include "CandyFactory.h"

class ChocolateFactory :
    private CandyFactory
{
protected:
    unsigned int sweetness;
public:
    ChocolateFactory();
    ChocolateFactory(unsigned int material,
                     unsigned int maxPower,
                     string candyName,
                     unsigned int materialCost,
                     unsigned int sweetness);
    void Craft(unsigned int amount);
    void ChocolateFactoryInfo();
};

