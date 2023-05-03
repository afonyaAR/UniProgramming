#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(int hours = 0,
		int minutes = 0,
		int seconds = 0) 
	{
		int minsToAdd = 0;
		int hrsToAdd = 0;
		if (seconds < 0 || seconds > 59)
		{
			minsToAdd = seconds / 60;
			this->seconds = seconds % 60;
		}
		if (hours < 0)
		{
			this->hours = 0;
		}
		else
		{
			this->hours = hours;
		}

		if (minutes < 0 || minutes > 59)
		{
			this->minutes = 
		}
	}
};

