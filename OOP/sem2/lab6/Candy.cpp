#include "Candy.h"

Candy::Candy()
{
	this->candyName = "unknown";
	this->materialCost = 0;
}

Candy::Candy(string candyName,
	unsigned int materialCost)
{
	this->candyName = candyName;
	this->materialCost = materialCost;
}

void Candy::ChangeCost(unsigned int materialCost)
{
	this->materialCost = materialCost;
	cout << "Changing material cost to " << materialCost << endl;
}

void Candy::CandyInfo()
{
	cout << "Candy name: " << this->candyName << endl;
	cout << "Material cost: " << this->materialCost << endl;
}