#include <iostream>
#include "Pet.h"
#include "Dog.h"
#include "Parrot.h"
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
    Dog dog1 = Dog("sharik", "tramp", 100, 100, 1, 2);

    Dog dog2 = Dog("harik", "shepherd", 100, 100, 1, 2);

    dog1.AddSkill("sit", 30, "im sittin'");
    dog1.AddSkill("tell story", 200, "story");

    dog1.DoSkill("sit");
    dog1.DoSkill("tell story");

    dog1.WalkPet(1);

    dog1.InfoPet();
    dog2.InfoPet();
}

void runUnitest3() 
{
    Parrot parrots[2];
    Parrot parrot1 = Parrot("pero", "ara", 100, 100, 2, 3);
    parrot1.Repeat("ew");
    Parrot parrot2 = Parrot();
    parrot2.Repeat("waw");
    parrot1.Fly(19);
    parrot1.Fly(1);
    Parrot::InfoPet("kwar", "ara");
    parrots[0].InfoPet();
}

int main()
{
    setlocale(0, "");

}
