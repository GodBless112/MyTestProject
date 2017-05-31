// static.cpp -- using a static local variable
#include <cstdlib>
#include<iostream>
#include<string>
#include "test.h"
// constants
// function prototype
using namespace std;
class demo
{
private:
	string word;
public:
	demo(const string & str)
	{
		word = str;
		cout << "demo " << word << " created\n";
	}
	~demo()
	{
		cout << "demo " << word << " destroyed\n";
	}
	void show() const
	{
		cout << "demo " << word << " lives!\n";
	}
};
double means(double a, double b);
double hmean(double a, double b);
double gmean(double a, double b);
int main(void)
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter two numbers: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
				cout << "Enter next pair:";
			}
			catch (bad_hmean & bg)
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean & hg)
			{
				cout << hg.mesg();
				cout << "Value used: " << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Sorry, you don't get to play any more.\n";
				break;
			}
		}
		d1.show();
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
		throw bad_hmean(a, b);
	return 2.0*a*b / (a + b);
	
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a*b);
}
double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in mean()");
	am = (a + b) / 2.0;
	try
	{
		hm = hmean(a, b);
		gm = gmean(a, b);
	}
	catch(bad_hmean & bg)
	{
		bg.mesg();
		cout << "Caught in means()\n";
		throw;
	}
	d2.show();
	return (am + hm + gm) / 3.0;
}


