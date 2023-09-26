#include "Factory.h"

Factory::Factory()
{
	this->material = 0;
	this->maxPower = 1;
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
	cout << "Adding " << amount << " material" << endl;
}

void Factory::SetPower()
{
	cout << "Enter power (max power = " << maxPower << "): ";
	cin >> power;
	if (power > maxPower)
	{
		cout << "Factory cant work on this power" << endl;
		SetPower();
	}
	else
	{
		this->power = power;
		cout << "Changing power to " << power << endl;
	}
}