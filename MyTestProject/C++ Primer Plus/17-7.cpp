// static.cpp -- using a static local variable
#include<iostream>
#include<cmath>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "Left Justfication:\n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "!";
		cout.width(12);
		cout << sqrt(double(n)) << "!\n";
	}
	cout.setf(old, ios_base::floatfield);
	cout << "Internal Justficantion:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "!";
		cout.width(12);
		cout << sqrt(double(n)) << "!\n";
	}
	cout << true << "!\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



