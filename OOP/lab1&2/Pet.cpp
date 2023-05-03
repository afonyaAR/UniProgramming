#include "Pet.h"

string Pet::getBreed() { return breed; };
string Pet::getName() { return name; };
int Pet::getSaturationPer() { return saturationPer; };
int Pet::getHealthPer() { return healthPer; };

void Pet::setBreed(string breed) { this->breed = breed; }
void Pet::setName(string name) { this->name = name; }
void Pet::setHealthPer(int healthPer)
{
    if (healthPer < 0 || healthPer > 100)
    {
        cout << "Установлено невозможное значение здоровья.";
        cout << "Установлено начальное значение здоровья: 50";
        this->healthPer = 50;
    }
    else this->healthPer = healthPer;
}
void Pet::setSaturationPer(int saturationPer)
{
    if (saturationPer < 0 || saturationPer > 100)
    {
        cout << "Установлено невозможное значение сытости.";
        cout << "Установлено начальное значение сытости: 0";
        this->saturationPer = 0;
    }
    else this->saturationPer = saturationPer;
}

void Pet::feedPet(int amount)
{
    if (saturationPer == 100)
    {
        cout << breed << " " << name << " сытый\n";
    }
    else
    {
        int eaten = saturationPer + amount;
        eatenFood = eaten > 100 ? 100 - saturationPer : amount;
        saturationPer = eaten > 100 ? 100 : eaten;
        cout << breed << " " << name << " съел " << eatenFood << "% от своей сытости.\n";
        cout << "Сытость питомца " << name << ": " << saturationPer << "%\n";
    }
    cout << endl;
}

void Pet::infoPet()
{
    cout << "Имя питомца: " << name << endl;
    cout << "Порода питомца: " << breed << endl;
    cout << "Здоровье питомца: " << healthPer << endl;
    cout << "Сытость питомца: " << saturationPer << endl;
    cout << endl;
}
void Pet::infoPet(string name, string breed)
{
    cout << "Имя питомца: " << name << endl;
    cout << "Порода питомца: " << breed << endl;
    cout << "Здоровье питомца: " << healthPer << endl;
    cout << "Сытость питомца: " << saturationPer << endl;
    cout << endl;
}
void Pet::infoPet(string name, string breed, int healthPer, int saturationPer)
{
    cout << "Имя питомца: " << name << endl;
    cout << "Порода питомца: " << breed << endl;
    cout << "Здоровье питомца: " << healthPer << endl;
    cout << "Сытость питомца: " << saturationPer << endl;
    cout << endl;
}

void Pet::walkPet(int hours)
{
    if (hours > saturationPer / 10)
    {
        cout << "Слишком длинная прогулка, питомец не выдержит.\n";
    }
    else
    {
        saturationPer -= hours * 10;
        cout << breed << " " << name << " погулял " << hours << " часов.\n";
        cout << "Сытость питомца " << name << ": " << saturationPer << "%\n";
    }
    cout << endl;
}
