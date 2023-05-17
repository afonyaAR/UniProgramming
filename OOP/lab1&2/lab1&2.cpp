#include <iostream>
#include "Pet.h"
#include "Dog.h"
using namespace std;

void runUnitest1()
{
    Pet pets[2];

    pets[1] = Pet("ZaakenZluken", "sheepdog", 30, 40);
    pets[0].SetBreed("shpits");
    pets[0].SetName("Nastya");
    pets[0].SetHealth(100);
    pets[0].SetSaturation(100);


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

void runUnitest2()
{
    
}

int main()
{
    setlocale(0, "");
    
  /*Dog dogs[2];
    
    dogs[0] = Dog("sharik", "idk", 100, 100, 1, 2);
    dogs[1] = Dog("harik", "idk", 100, 100, 1, 2);

    dogs[0].AddSkill("sit", 30, "im sittin'");
    dogs[0].AddSkill("tell story", 200, "story");
    dogs[0].DoSkill("sit");
    dogs[0].DoSkill("tell story");

    for (int i = 0; i < 2; i++)
    {
        dogs[i].InfoPet(); 
    }*/
}
