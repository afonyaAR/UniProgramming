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
	virtual void Craft(unsigned int amount) = 0;
	void AddMaterial(unsigned int amount);
	void SetPower();
};
