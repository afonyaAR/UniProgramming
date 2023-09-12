#include "Factory.h"

Factory::Factory()
{
	this->material = 0;
	this->maxPower = 0;
	this->power = 0;
}

Factory::Factory(unsigned int material,
	unsigned int maxPower)
{
	this->material = material;
	this->maxPower = maxPower;
	this->power = 0;
}

void Factory::AddMaterial(unsigned int amount)
{
	this->material += amount;
	cout << "Adding " << amount << " material";
}

void Factory::SetMaxPower(unsigned int maxPower)
{
	this->maxPower = maxPower;
	cout << "Changing max power to " << maxPower;
}

void Factory::SetPower(unsigned int power)
{
	if (power > maxPower)
	{
		cout << "Factory cant work on this power";
	}
	else
	{
		this->power = power;
		cout << "Changing power to " << power;
	}
}