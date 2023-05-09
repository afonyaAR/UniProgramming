#pragma once
#include <iostream>
using namespace std;

class Pet
{
private:
    string breed;
    string name;
    unsigned int health;
    unsigned int saturation;
public:
    Pet() : Pet("unknown_name", "unknown_breed", 0, 0) {};
    Pet(string breed, string name, unsigned int healthPer, unsigned int saturationPer);

    string GetBreed();
    string GetName();
    int GetSaturation();
    int GetHealth();

    void SetBreed(string breed);
    void SetName(string name);
    void SetHealth(unsigned int health);
    void SetSaturation(unsigned int saturation);

    void FeedPet() { FeedPet(100); };
    void FeedPet(unsigned int amount);

    void WalkPet() { WalkPet(1); };
    void WalkPet(unsigned int hours);

    void InfoPet();
};
