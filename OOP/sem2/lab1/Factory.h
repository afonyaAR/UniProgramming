#pragma once
#include <iostream>
using namespace std;

class Factory
{
protected:
	unsigned int material;
	unsigned int maxPower;
	unsigned int power;
public:
	Factory();
	Factory(unsigned int material,
		unsigned int maxPower);
	virtual void Craft(unsigned int amount) const = 0;
	void AddMaterial(unsigned int amount);
	void SetMaxPower(unsigned int maxPower);
	void SetPower(unsigned int power);
};

