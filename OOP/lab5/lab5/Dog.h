#pragma once
#include "Pet.h"
#include <map>

class Dog : public Pet
{
private:
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

    void AddSkill(string skillName, unsigned int difficulty, string skillAnswer);
    void DoSkill(string skillName);
    void MakeSound() const override;
    void InfoPet() const override;
};

