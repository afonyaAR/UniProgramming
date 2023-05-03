#include <iostream>
#include "Pet.h"
using namespace std;

void runUnitest()
{
    Pet pets[2];

    pets[0].setBreed("шпиц");
    pets[0].setName("Настя");
    pets[0].setHealthPer(100);
    pets[0].setSaturationPer(10);

    pets[1] = Pet("овчарка", "Закензлюкен", 30, 40);

    for (int i = 0; i < 2; i++)
    {
        pets[i].infoPet();
    }

    pets[0].feedPet(50);
    pets[0].walkPet(4);
    pets[0].walkPet(3);
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
    Pet pet;
    pet.infoPet("собачонка", "абобик");
}
