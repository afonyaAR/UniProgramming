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
	Dog();
	Dog(string name, string breed,
		unsigned int health,
		unsigned int saturation,
		unsigned int learnAbility,
		unsigned int maxSkills);
	
	void Bark();
	void AddSkill(string skillName, unsigned int difficulty, string skillAnswer);
	void DoSkill(string skillName);
	void InfoPet();
	static void InfoPet(string name, string breed);
};

