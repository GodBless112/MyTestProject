// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
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
	int number,N;
	double sum, max, min, average;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		cout << "Enter the test number: ";
		if (!(cin >> number))
			break;
		N = number;
		min = max = sum = average = 0.0;
		while (number)
		{
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			if (max == 0.0 || min == 0.0)
				max = min = steps;
			if (max < steps)
				max = steps;
			if (min > steps)
				min = steps;
			sum += steps;
				
			steps = 0;
			number--;
			result.reset(0.0, 0.0);
		}
		average = sum / N;
		cout << "The max steps is: " << max << endl;
		cout << "The min steps is: " << min << endl;
		cout << "the average steps is: " << average << endl;
		cout << "Enter target distance(q to quit): ";
	}
	cout << "Bye!\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


