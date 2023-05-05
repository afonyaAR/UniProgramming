#include <iostream>
#include "Pet.h"
using namespace std;

void runUnitest()
{
    Pet pets[2];

    pets[0].setBreed("shpits");
    pets[0].setName("Nastya");
    pets[0].setHealth(100);
    pets[0].setSaturation(100);

    pets[1] = Pet("sheepdog", "ZaakenZluken", 30, 40);

    for (int i = 0; i < 2; i++)
    {
        pets[i].infoPet();
    }

    pets[0].feedPet(50);
    pets[0].walkPet(4);
    pets[0].walkPet(3);
    pets[0].walkPet();
    pets[0].feedPet(50);

    pets[1].feedPet(40);
    pets[1].feedPet(40);
    pets[1].walkPet(1);

    for (int i = 0; i < 2; i++)
    {
        pets[i].infoPet();
    }
}

int main()
{
    setlocale(0, "");
    runUnitest();
}
