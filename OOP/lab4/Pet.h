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
        unsigned int healthPer, 
        unsigned int saturationPer);

    string GetName();
    string GetBreed();
    int GetSaturation();
    int GetHealth();

    void SetName(string name);
    void SetBreed(string breed);
    void SetHealth(unsigned int health);
    void SetSaturation(unsigned int saturation);

    void FeedPet() { FeedPet(100); };
    void FeedPet(unsigned int amount);

    void WalkPet() { WalkPet(1); };
    void WalkPet(unsigned int hours);

    void InfoPet();
};
