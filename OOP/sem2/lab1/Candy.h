#pragma once
#include <iostream>
using namespace std;

class Candy
{
protected:
	string candyName;
	unsigned int materialCost;
	unsigned int sweetness;
public:
	Candy();
	Candy(string candyName,
		unsigned int materialCost);
	void ChangeCost(unsigned int materialCost);
};

