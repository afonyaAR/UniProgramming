#include "Pet.h"

Pet::Pet(string name, string breed, unsigned int health, unsigned int saturation)
{
    this->name = name;
    this->breed = breed;
    this->health = health;
    this->saturation = saturation;
}

string Pet::getBreed() { return breed; };
string Pet::getName() { return name; };
int Pet::getSaturation() { return saturation; };
int Pet::getHealth() { return health; };

void Pet::setBreed(string breed) { this->breed = breed; }
void Pet::setName(string name) { this->name = name; }
void Pet::setHealth(unsigned int health) { this->health = health; }
void Pet::setSaturation(unsigned int saturation)
{
    if (saturation > 100 || saturation < 0)
    {
        this->saturation = 100;
        cout << "Wrong number (must be percent), default saturation = 100";
    }
    else
    {
        this->saturation = saturation;
    }
}

void Pet::feedPet()
{
    saturation = 100;
    cout << breed << " " << name << "now is full" << endl;
    cout << endl;
}
void Pet::feedPet(unsigned int amount)
{
    if (saturation == 100)
    {
        cout << breed << " " << name << " is full and cant eat anymore" << endl;
    }
    else if (saturation + amount >= 100)
    {
        cout << breed << " " << name << " ate " << 100 - saturation << " and now full" << endl;
        cout << "Remainings: " << (saturation + amount) % 100 << endl;
        saturation = 100;
    }
    else
    {
        saturation += amount;
        cout << breed << " " << name << " ate: " << amount << endl;
    }
    cout << endl;
}

void Pet::infoPet()
{
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Health: " << health << endl;
    cout << "Saturation: " << saturation << endl;
    cout << endl;
}

void Pet::walkPet(unsigned int hours)
{
    if (hours > saturation / 10)
    {
        cout << "This so much for this pet, try to feed them more or less walk" << endl;
    }
    else
    {
        saturation -= hours * 10;
        cout << "After " << hours << " hours of walk " << breed << " " << name << " saturation is: " << saturation << endl;
    }
    cout << endl;
}
