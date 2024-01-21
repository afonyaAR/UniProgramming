#include "Parrot.h"

Parrot::Parrot(string name, string breed,
	unsigned int health,
	unsigned int saturation,
	unsigned int flyTime,
	unsigned int noisyness) : Pet(name, breed, health, saturation)
{
	this->flyTime = flyTime;
	this->noisyness = noisyness;
}

Parrot::Parrot()
{
	this->name = "perrito";
	this->breed = "unknown";
	this->health = 0;
	this->saturation = 0;
	this->flyTime = 0;
	this->noisyness = 0;
}

void Parrot::Fly(unsigned int meters)
{
	if (meters % flyTime > 0)
	{
		if ((meters / flyTime + 1) * 10 > saturation)
		{
			cout << name << " dont have enough saturation to fly that much." << endl;
		}
		else
		{
			saturation -= (meters / flyTime + 1) * 10;
			cout << name << " flew around " << (meters / flyTime + 1) * flyTime << " meters." << endl;
		}
	}
	else
	{
		if ((meters / flyTime) * 10 > saturation)
		{
			cout << name << " dont have enough saturation to fly that much." << endl;
		}
		else
		{
			saturation -= (meters / flyTime) * 10;
			cout << name << " flew around " << meters << " meters." << endl;
		}
	}
}

void Parrot::Repeat(string text)
{
	for (int i = 0; i < noisyness; i++)
	{
		cout << "kwar! ";
	}
	cout << text << " - parrot says." << endl;
}

void Parrot::MakeSound() const 
{
	for (int i = 0; i < noisyness; i++)
	{
		cout << "kwar! ";
	}
	cout << "- parrot says." << endl;
}


void Parrot::InfoPet() const
{
	Pet::InfoPet();
	cout << "Fly time: " << flyTime << endl;
	cout << "Noisyness: " << noisyness << endl;
}
