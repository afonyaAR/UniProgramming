#include "Dog.h"
#include <map>

void Dog::Bark() { cout << "Bark!!!"; }
void Dog::AddSkill(string skillName, unsigned int difficulty, string skillAnswer)
{
	if (learnAbility > 0)
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
		cout << skills[skillName] << "!!!";
	}
	else
	{
		cout << name << " dont know this skill.";
	}
}
