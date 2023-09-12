#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time lunchTime = Time(1, 24, 1);
	lunchTime.ShowTime();
	Time breakfastTime = lunchTime + Time(1, 59, 1);
	breakfastTime.ShowTime();
	breakfastTime = lunchTime + 560;
	breakfastTime.ShowTime();
	breakfastTime.ShowSeconds();
	breakfastTime += 43;
	breakfastTime.ShowSeconds();
	Time::ShowTime(1500);
}
