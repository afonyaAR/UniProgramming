#pragma once
#include <iostream>
using namespace std;

class Pet
{
private:
    string breed;
    string name;
    int healthPer;
    int saturationPer;
    int eatenFood;

public:
    Pet(string breed = "овчарка",
        string name = "баобик",
        int healthPer = 100,
        int saturationPer = 100)
    {
        this->breed = breed;
        this->name = name;
        this->healthPer = healthPer;
        this->saturationPer = saturationPer;
        this->eatenFood = 0;
    }

    string getBreed();
    string getName();
    int getSaturationPer();
    int getHealthPer();

    void setBreed(string breed);
    void setName(string name);
    void setHealthPer(int healthPer);
    void setSaturationPer(int saturationPer);

    void feedPet(int amount = 10);
    void infoPet();
    void infoPet(string name, string breed);
    void infoPet(string name, string breed, int healthPer, int saturationPer);
    void walkPet(int hours = 1);
};
