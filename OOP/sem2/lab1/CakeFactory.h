#pragma once
#include "CandyFactory.h"

class CakeFactory:
	public CandyFactory
{
protected:
	bool sprinkles;
public:
	CakeFactory();
	CakeFactory(unsigned int material,
				unsigned int maxPower,
				string candyName,
				unsigned int materialCost,
				bool sprinkles);
	void Craft(unsigned int amount);
	void CakeFactoryInfo();
};

