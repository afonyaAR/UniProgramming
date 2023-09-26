#include "CakeFactory.h"

CakeFactory::CakeFactory() :
	CandyFactory()
{
	this->sprinkles = false;
}

CakeFactory::CakeFactory(unsigned int material,
						 unsigned int maxPower,
						 string candyName,
						 unsigned int materialCost,
						 bool sprinkles) :
	CandyFactory(material, maxPower, candyName, materialCost)
{
	this->sprinkles = sprinkles;
}

void CakeFactory::Craft(unsigned int amount)
{
	CandyFactory::Craft(amount);
}

void CakeFactory::CakeFactoryInfo()
{
	CandyFactory::CandyFactoryInfo();
	cout << "Sprinkles on cake: " << this->sprinkles << endl;
}
