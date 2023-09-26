#pragma once
#include <iostream>
#include "Candy.h"
#include "Factory.h"
using namespace std;

class CandyFactory:
	private Factory, public Candy
{
public:
	CandyFactory();
	CandyFactory(unsigned int material,
				 unsigned int maxPower,
				 string candyName,
				 unsigned int materialCost);
	void Craft(unsigned int amount);
	void CandyFactoryInfo();
};

