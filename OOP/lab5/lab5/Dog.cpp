#include "Dog.h"
#include <map>

Dog::Dog(string name, string breed,
	unsigned int health,
	unsigned int saturation,
	unsigned int learnAbility,
	unsigned int maxSkills) : Pet(name, breed, health, saturation)
{
	this->learnAbility = learnAbility;
	this->maxSkills = maxSkills;
}

Dog::Dog()
{
	this->name = "doggy";
	this->breed = "tramp";
	this->health = 0;
	this->saturation = 0;
	this->learnAbility = 0;
	this->maxSkills = 0;
}

void Dog::AddSkill(string skillName, unsigned int difficulty, string skillAnswer)
{
	if (learnAbility > 0 && maxSkills > 0)
	{
		if (saturation > difficulty / learnAbility)
		{
			skills[skillName] = skillAnswer;
			cout << name << " succesfully learned skill: " << skillName << "." << endl;
		}
		else
		{
			cout << name << " dont have enough saturation to learn this." << endl;
		}
		--maxSkills;
	}
	else
	{
		cout << name << " cant teach more skills." << endl;
	}
}
void Dog::DoSkill(string skillName)
{
	if (skills.find(skillName) != skills.end())
	{
		cout << skills[skillName] << "!!!" << endl;
	}
	else
	{
		cout << name << " dont know this skill." << endl;
	}
}

void Dog::MakeSound() const
{
	cout << "Bark" << endl;
}

void Dog::InfoPet() const 
{
	Pet::InfoPet();
	cout << "Learn ability: " << learnAbility << endl;
	cout << "Max skills (left): " << maxSkills << endl;
}