#include "Pet.h"

Pet::Pet() 
{
    this->name = "unknown_name";
    this->breed = "unknown_breed";
    this->health = 0;
    this->saturation = 0;
}

Pet::Pet(string name, string breed, unsigned int health, unsigned int saturation)
{
    this->name = name;
    this->breed = breed;
    this->health = health;
    this->saturation = saturation;
}

string Pet::GetBreed() { return breed; };
string Pet::GetName() { return name; };
int Pet::GetSaturation() { return saturation; };
int Pet::GetHealth() { return health; };

void Pet::SetBreed(string breed) { this->breed = breed; }
void Pet::SetName(string name) { this->name = name; }
void Pet::SetHealth(unsigned int health) { this->health = health; }
void Pet::SetSaturation(unsigned int saturation)
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

void Pet::FeedPet(unsigned int amount)
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
}

void Pet::InfoPet()
{
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Health: " << health << endl;
    cout << "Saturation: " << saturation << endl;
}

void Pet::WalkPet(unsigned int hours)
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
}
