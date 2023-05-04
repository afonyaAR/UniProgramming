#include "Pet.h";

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
        cout << "Óñòàíîâëåíî íåâîçìîæíîå çíà÷åíèå çäîðîâüÿ.";
        cout << "Óñòàíîâëåíî íà÷àëüíîå çíà÷åíèå çäîðîâüÿ: 50";
        this->healthPer = 50;
    }
    else this->healthPer = healthPer;
}
void Pet::setSaturationPer(int saturationPer)
{
    if (saturationPer < 0 || saturationPer > 100)
    {
        cout << "Óñòàíîâëåíî íåâîçìîæíîå çíà÷åíèå ñûòîñòè.";
        cout << "Óñòàíîâëåíî íà÷àëüíîå çíà÷åíèå ñûòîñòè: 0";
        this->saturationPer = 0;
    }
    else this->saturationPer = saturationPer;
}

void Pet::feedPet(int amount)
{
    if (saturationPer == 100)
    {
        cout << breed << " " << name << " ñûòûé\n";
    }
    else
    {
        int eaten = saturationPer + amount;
        eatenFood = eaten > 100 ? 100 - saturationPer : amount;
        saturationPer = eaten > 100 ? 100 : eaten;
        cout << breed << " " << name << " ñúåë " << eatenFood << "% îò ñâîåé ñûòîñòè.\n";
        cout << "Ñûòîñòü ïèòîìöà " << name << ": " << saturationPer << "%\n";
    }
    cout << endl;
}

void Pet::infoPet()
{
    cout << "Èìÿ ïèòîìöà: " << name << endl;
    cout << "Ïîðîäà ïèòîìöà: " << breed << endl;
    cout << "Çäîðîâüå ïèòîìöà: " << healthPer << endl;
    cout << "Ñûòîñòü ïèòîìöà: " << saturationPer << endl;
    cout << endl;
}
void Pet::infoPet(string name, string breed)
{
    cout << "Èìÿ ïèòîìöà: " << name << endl;
    cout << "Ïîðîäà ïèòîìöà: " << breed << endl;
    cout << "Çäîðîâüå ïèòîìöà: " << healthPer << endl;
    cout << "Ñûòîñòü ïèòîìöà: " << saturationPer << endl;
    cout << endl;
}
void Pet::infoPet(string name, string breed, int healthPer, int saturationPer)
{
    cout << "Èìÿ ïèòîìöà: " << name << endl;
    cout << "Ïîðîäà ïèòîìöà: " << breed << endl;
    cout << "Çäîðîâüå ïèòîìöà: " << healthPer << endl;
    cout << "Ñûòîñòü ïèòîìöà: " << saturationPer << endl;
    cout << endl;
}

void Pet::walkPet(int hours)
{
    if (hours > saturationPer / 10)
    {
        cout << "Ñëèøêîì äëèííàÿ ïðîãóëêà, ïèòîìåö íå âûäåðæèò.\n";
    }
    else
    {
        saturationPer -= hours * 10;
        cout << breed << " " << name << " ïîãóëÿë " << hours << " ÷àñîâ.\n";
        cout << "Ñûòîñòü ïèòîìöà " << name << ": " << saturationPer << "%\n";
    }
    cout << endl;
}
