#include "Parrot.h"

Parrot::Parrot() 
{
	this->name = "perrito";
	this->breed = "unknown";
	this->health = 0;
	this->saturation = 0;
	this->flyTime = 0;
	this->noisyness = 0;
}

Parrot::Parrot(string name, string breed,
	unsigned int health,
	unsigned int saturation,
	unsigned int flyTime,
	unsigned int noisyness) : Pet(name, breed, health, saturation)
{
	this->flyTime = flyTime;
	this->noisyness = noisyness;
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
		if ((meters / flyTime)*10 > saturation)
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

void Parrot::InfoPet() 
{
	Pet::InfoPet();
	cout << "Fly time: " << flyTime << endl;
	cout << "Noisyness: " << noisyness << endl;
}

void Parrot::InfoPet(string name, string breed) 
{
	cout << name << " " << breed << " is a good parrot." << endl;
}