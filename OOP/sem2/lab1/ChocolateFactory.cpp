#include "ChocolateFactory.h"

ChocolateFactory::ChocolateFactory() :
	CandyFactory()
{
	this->sweetness = 0;
}

ChocolateFactory::ChocolateFactory(unsigned int material,
								   unsigned int maxPower,
								   string candyName,
								   unsigned int materialCost,
								   unsigned int sweetness):
	CandyFactory(material, maxPower, candyName, materialCost)
{
	this->sweetness = sweetness;
}

void ChocolateFactory::Craft(unsigned int amount)
{
	CandyFactory::Craft(amount);
}

void ChocolateFactory::ChocolateFactoryInfo()
{
	CandyFactory::CandyFactoryInfo();
	cout << "sweetness: " << this->sweetness;
}