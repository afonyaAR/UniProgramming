#pragma once
#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;
    string breed;
    unsigned int health;
    unsigned int saturation;
public:
    Pet();
    Pet(string name, string breed,
        unsigned int health,
        unsigned int saturation);

    void FeedPet(unsigned int amount);
    void Play(unsigned int hours);
    virtual void MakeSound() const = 0;
    virtual void InfoPet() const = 0;
};

