// static.cpp -- using a static local variable
#include<iostream>
#include<iomanip>
#include<cmath>
#include<exception>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	cout << "Enter numbers: ";
	int sum = 0;
	int input;
	while (cin >> input)
	{
		sum += input;
	}
	
	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



