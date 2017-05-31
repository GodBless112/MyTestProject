#include <iostream>
#include "test.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
	//hours %= 24;
}
void Time::Reset(int h,int m)
{
	hours = h;
	minutes = m;
}
Time Time::Sum(const Time & t) const
{
	Time temp;
	temp.minutes = minutes + t.minutes;
	temp.hours = hours + t.hours + temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}
void Time::Show() const
{
	if (hours > 9)
		std::cout << hours << "hours";
	else
		std::cout << '0' << hours << "hours";
	if (minutes > 9)
		std::cout << minutes << "minutes";
	else
		std::cout << '0' << minutes << "minutes";
	std::cout << std::endl;
}