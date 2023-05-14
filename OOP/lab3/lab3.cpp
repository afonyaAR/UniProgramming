#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time lunchTime = Time(1, 24, 1);
	Time breakfastTime = lunchTime + Time(1, 59, 1);
	breakfastTime.ShowTime();
	breakfastTime = lunchTime + 560;
	breakfastTime.ShowTime();
	breakfastTime += 43;
	breakfastTime.ShowSeconds();
}
