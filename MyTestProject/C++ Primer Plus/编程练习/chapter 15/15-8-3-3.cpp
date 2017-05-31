// static.cpp -- using a static local variable
#include <cstdlib>
#include<iostream>
#include<typeinfo>
#include "test.h"
// constants
// function prototype
using namespace std;
double hmean(double a, double b);
double gmean(double a, double b);
int main(void)
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers<q to quit>: ";
		}
		catch (bad_mean & bm)
		{
			bm.mesg();
			if (typeid(bm)==typeid(bad_hmean))
			{
				cout << "Try again.\n";
				continue;
			}
			else if (typeid(bm) == typeid(bad_gmean))
			{
				cout << "Sorry, you don't play any more!\n";
				break;
			}
			
		}
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
		throw bad_hmean(a,b);
	return 2.0*a*b / (a + b);

}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a*b);
}


