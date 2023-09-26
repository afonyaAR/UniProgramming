#include "Candy.h"
#include "Factory.h"
#include "CandyFactory.h"
#include "ChocolateFactory.h"
#include "CakeFactory.h"
#include <iostream>
using namespace std;

int main()
{
	CandyFactory cf = CandyFactory(1000, 10, "Aleshka", 15);
	cf.CandyFactoryInfo();
	cf.Craft(100);
	cf.ChangeCost(10);
	cf.CandyFactoryInfo();
	cf.Craft(5);

	CandyFactory cf2 = CandyFactory();
	cf2.CandyFactoryInfo();
	cf2.Craft(10);

	ChocolateFactory chf = ChocolateFactory(500, 15, "Nats", 10, 10);
	chf.ChocolateFactoryInfo();
	chf.Craft(10);
	chf.ChocolateFactoryInfo();

	CakeFactory ckf = CakeFactory(100, 2, "Cheesecake", 25, false);
	ckf.CakeFactoryInfo();
	ckf.Craft(3);
	ckf.CakeFactoryInfo();

}