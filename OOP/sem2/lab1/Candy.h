#pragma once
#include <iostream>
using namespace std;

class Candy
{
protected:
	string candyName;
	unsigned int materialCost;
public:
	Candy();
	Candy(string candyName,
		  unsigned int materialCost);
	void ChangeCost(unsigned int materialCost);
	void CandyInfo();
};

