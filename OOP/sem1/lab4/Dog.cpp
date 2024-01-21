#include "Dog.h"
#include <map>

Dog::Dog()
{
	this->name = "doggy";
	this->breed = "tramp";
	this->health = 0;
	this->saturation = 0;
	this->learnAbility = 0;
	this->maxSkills = 0;
}

Dog::Dog(string name, string breed,
	unsigned int health,
	unsigned int saturation,
	unsigned int learnAbility,
	unsigned int maxSkills) : Pet(name, breed, health, saturation)
{
	this->learnAbility = learnAbility;
	this->maxSkills = maxSkills;
}

void Dog::Bark() { cout << "Bark!!!"; }
void Dog::AddSkill(string skillName, unsigned int difficulty, string skillAnswer)
{
	if (learnAbility > 0 && maxSkills > 0)
	{
		if (saturation > difficulty/learnAbility)
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

void Dog::InfoPet()
{
	Pet::InfoPet();
	cout << "Learn ability: " << learnAbility << endl;
	cout << "Max skills: " << maxSkills << endl;
}

void Dog::InfoPet(string name, string breed) 
{
	cout << name << " " << breed << " is a good dog.";
}