#include "Pet.h"
#include "Dog.h"
#include "Parrot.h"
#include <iostream>
using namespace std;

int main()
{
    Dog dogs[2];
    dogs[0] = Dog("sharik", "tramp", 100, 100, 1, 2);
    dogs[1] = Dog("harik", "shepherd", 100, 100, 1, 2);
    Parrot parrots[2];
    parrots[0] = Parrot("pero", "ara", 100, 100, 2, 3);
    parrots[1] = Parrot("perolta", "kakdu", 30, 70, 0, 1);

    dogs[0].InfoPet();
    dogs[0].MakeSound();
    cout << endl;
    dogs[1].InfoPet();
    dogs[1].MakeSound();
    cout << endl;
    parrots[0].InfoPet();
    parrots[0].MakeSound();
    cout << endl;
    parrots[1].InfoPet();
    parrots[1].MakeSound();
}