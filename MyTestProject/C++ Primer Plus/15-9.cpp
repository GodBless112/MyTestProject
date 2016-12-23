// static.cpp -- using a static local variable
#include <cstdlib>
#include<iostream>
#include "test.h"
// constants
// function prototype
using namespace std;
double hmean(double a, double b);
int main(void)
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
		}
		catch (const char * s)
		{
			cout << s << endl;
			cout << "Enter a new pair of numbers: ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers<q to quit>: ";
	}
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
double hmean(double a, double b)
{
	if (a == -b)
		throw "bad hmwan() arguments: a = -b not allowed";
	return 2.0*a*b / (a + b);
	
}


 