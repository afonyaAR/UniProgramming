#pragma once
#include "Pet.h"
class Dog : public Pet
{
private:
	unsigned int learnAbility;
	unsigned int maxSkills;
public:
	Dog() : Pet::Pet() {};
	Dog(string dogName, string dogBreed, unsigned int health, unsigned int saturation) : Pet::Pet(dogName, dogBreed, health, saturation) {};
	void Bark();
	void AddSkill(string skillName, unsigned int difficulty);
	void DoSkill(string skillName);
};

