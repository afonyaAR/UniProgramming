#include "CandyFactory.h"

CandyFactory::CandyFactory() :
	Candy(),
	Factory(){}

CandyFactory::CandyFactory(unsigned int material,
	unsigned int maxPower,
	string candyName,
	unsigned int materialCost):
	Candy(candyName, materialCost),
	Factory(material, maxPower){}

void CandyFactory::Craft(unsigned int amount)
{
	if (material < amount * materialCost)
	{
		cout << "Not enough materials, add more or decrease amount";
	}
	else
	{
		if (power == 0)
		{
			cout << "Factory isnt worikng";
		}
		else
		{
			this->material -= amount * materialCost;
			cout << amount << " " << candyName << "'s were successfully crafted";
			cout << amount * materialCost << " materials were used";
			cout << amount / power << " hours were spent";
		}
	}
}