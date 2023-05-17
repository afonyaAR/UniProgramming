#pragma once
#include "Pet.h"
#include <map>
class Dog : public Pet
{
protected:
	unsigned int learnAbility;
	unsigned int maxSkills;
	map<string, string> skills;
public:
	Dog() : Dog(name = "doggy", breed = "tramp", health = 0, saturation = 0, learnAbility = 0, maxSkills = 0) {};
	Dog(string name, string breed,
		unsigned int health,
		unsigned int saturation,
		unsigned int learnAbility,
		unsigned int maxSkills) : Pet(name, breed, health, saturation)
	{
		this->learnAbility = learnAbility;
		this->maxSkills = maxSkills;
	};
	
	void Bark();
	void AddSkill(string skillName, unsigned int difficulty, string skillAnswer);
	void DoSkill(string skillName);
};

