#include <iostream>
#include "Van.h"
using namespace std;
Van::Van(bool type, int number)
{
	this->type = type;
	this->number = number;
}

bool Van::VanType()
{
	return this->type;
}

void Van::VanInfo()
{
	cout << "Van " << number << "-" << type << endl;
}