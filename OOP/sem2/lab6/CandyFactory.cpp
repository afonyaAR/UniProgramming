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
	if (power == 0)
	{
		cout << "Factory isnt worikng" << endl;
		SetPower();
		Craft(amount);
	}
	else
	{
		if (material < amount * materialCost)
		{
			cout << "Not enough materials, ";
			AddMaterial(100);
			Craft(amount);
		}
		else
		{
			material -= amount * materialCost;
			cout << amount << " " << candyName << "'s were successfully crafted" << endl;
			cout << amount * materialCost << " materials were used" << endl;
			cout << (float)amount / power << " hours were spent" << endl;
		}
	}
}

void CandyFactory::CandyFactoryInfo()
{
	Candy::CandyInfo();
	cout << "materials: " << this->material << endl;
	cout << "power: " << this->power << endl;
}