// static.cpp -- using a static local variable
#include <cstdlib>
#include<iostream>
#include "test.h"
// constants
// function prototype
using namespace std;
bool hmean(double a, double b,double * ans);
int main(void)
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		if (hmean(x, y, &z))
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		else
			cout << "One value should not be the negative "
			<< "of the other - try again.\n";
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
bool hmean(double a, double b, double * ans)
{
	if (a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0*a*b / (a + b);
		return true;
	}
	
}


