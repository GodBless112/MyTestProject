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
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
Time operator+(const Time & t1, const Time & t2)
{
	Time temp;
	temp.minutes = t1.minutes + t2.minutes;
	temp.hours = t1.hours + t2.hours + temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}
Time operator-(const Time & t1, const Time & t2) 
{
	Time temp;
	int tot1, tot2;
	tot1 = t2.minutes + 60 * t2.hours;
	tot2 = t1.minutes + 60 * t1.hours;
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