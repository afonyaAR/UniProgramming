#include "Time.h"

Time::Time(int hours, int minutes, int seconds)
{
	if (seconds < 0 || seconds > 59 || minutes < 0 || minutes > 59 || hours < 0)
	{
		cout << "Time initialize error.";
		quick_exit(0);
	}
	else
	{
		this->seconds = seconds;
		this->minutes = minutes;
		this->hours = hours;
	}
}
void Time::ShowTime()
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}
void Time::ShowTime(const int seconds)
{
	int hours = seconds / 3600;
	int minutes = (seconds / 60) % 60;
	int _seconds = seconds % 60;
	cout << hours << ":" << minutes << ":" << _seconds << endl;
}
void Time::ShowSeconds()
{
	cout << "total time (in seconds): " << hours * 3600 + minutes * 60 + seconds << endl;
}
Time operator+(const Time& time1, const Time& time2)
{
	int newSeconds = time1.seconds + time2.seconds;
	int newMinutes = time1.minutes + time2.minutes + newSeconds / 60;
	int newHours = time1.hours + time2.hours + newMinutes / 60;
	return Time(newHours, newMinutes%60, newSeconds%60);
}
Time operator+(const Time& time, const int seconds)
{
	int newSeconds = time.seconds + seconds;
	int newMinutes = time.minutes + newSeconds / 60;
	int newHours = time.hours + newMinutes / 60;
	return Time(newHours, newMinutes % 60, newSeconds % 60);
}
Time operator+=(Time& time, const int seconds)
{
	int newSeconds = time.seconds + seconds;
	int newMinutes = time.minutes + newSeconds / 60;
	int newHours = time.hours + newMinutes / 60;
	return Time(time.hours = newHours, time.minutes = newMinutes % 60, time.seconds = newSeconds % 60);
}
