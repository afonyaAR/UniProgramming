#pragma once
#include "Pet.h"

class Parrot : public Pet
{
private:
	unsigned int flyTime;
	unsigned int noisyness;
public:
	Parrot();
	Parrot(string name,
		string breed,
		unsigned int health,
		unsigned int saturation,
		unsigned int flyTime,
		unsigned int noisyness);

	void Fly(unsigned int meters);
	void Repeat(string text);
	void MakeSound() const override;
	void InfoPet() const override;
};

