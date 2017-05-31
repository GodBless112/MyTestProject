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
Time Time::operator+(const Time & t) const
{
	Time temp;
	temp.minutes = minutes + t.minutes;
	temp.hours = hours + t.hours + temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}
Time Time::operator-(const Time & t) const
{
	Time temp;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	temp.minutes = (tot2 - tot1) % 60;
	temp.hours = (tot2 - tot1) / 60;
	temp.minutes %= 60;
	return temp;
}
Time Time::operator*(double n) const
{
	Time temp;
	long totalminutes = hours*n * 60 + minutes*n;
	temp.minutes = totalminutes % 60;
	temp.hours = totalminutes / 60;
	return temp;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	if (t.hours > 9)
		os << t.hours << "hours";
	else
		os << '0' << t.hours << "hours";
	if (t.minutes > 9)
		os << t.minutes << "minutes";
	else
		os << '0' << t.minutes << "minutes";
	os << std::endl;
	return os;
}