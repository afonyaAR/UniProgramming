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
	Time(): Time(0,0,0) {}
	Time(int seconds) : Time(seconds/3600, seconds%3600/60, seconds%60) {}
	Time(int hours, int minutes, int seconds);
	void ShowTime();
	void ShowSeconds();
	friend Time operator+(const Time& time1, const Time& time2);
	friend Time operator+(const Time& time1, const int seconds);
	friend Time operator+=(Time& time, const int seconds);
};

