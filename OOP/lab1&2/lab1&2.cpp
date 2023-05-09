#include <iostream>
#include "Pet.h"
using namespace std;

void runUnitest()
{
    Pet pets[2];

    pets[0].SetBreed("shpits");
    pets[0].SetName("Nastya");
    pets[0].SetHealth(100);
    pets[0].SetSaturation(100);

    pets[1] = Pet("sheepdog", "ZaakenZluken", 30, 40);

    for (int i = 0; i < 2; i++)
    {
        pets[i].InfoPet();
    }

    pets[0].FeedPet(50);
    pets[0].WalkPet(4);
    pets[0].WalkPet(3);
    pets[0].WalkPet();
    pets[0].FeedPet(50);

    pets[1].FeedPet(40);
    pets[1].FeedPet(40);
    pets[1].WalkPet(1);

    for (int i = 0; i < 2; i++)
    {
        pets[i].InfoPet();
    }
}

int main()
{
    setlocale(0, "");
    runUnitest();
}
