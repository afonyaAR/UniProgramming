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

void Pet::Play(unsigned int hours)
{
    if (hours > saturation / 10)
    {
        cout << "This is so much for this pet, try to feed them more or less play" << endl;
    }
    else
    {
        saturation -= hours * 10;
        cout << "After " << hours << " hours of playing " << breed << " " << name << " saturation is: " << saturation << endl;
    }
}

void Pet::InfoPet() const
{
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Health: " << health << endl;
    cout << "Saturation: " << saturation << endl;
}