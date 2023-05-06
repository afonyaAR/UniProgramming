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

    string getBreed();
    string getName();
    int getSaturation();
    int getHealth();

    void setBreed(string breed);
    void setName(string name);
    void setHealth(unsigned int health);
    void setSaturation(unsigned int saturation);

    void feedPet() { feedPet(100); };
    void feedPet(unsigned int amount);

    void walkPet() { walkPet(1); };
    void walkPet(unsigned int hours);

    void infoPet();
};
