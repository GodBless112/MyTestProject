// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout;
	fout.open("test.txt");
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			fout << steps << ": "<<result<<endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		fout << "After " << steps << " steps, the subject " << "has the following location:\n";
		fout << result << endl;
		cout << "After " << steps << " steps, the subject " << "has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl;
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance(q to quit): ";
	}
	cout << "Bye!\n";
	fout.close();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}