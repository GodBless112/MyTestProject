// static.cpp -- using a static local variable
#include<iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;
	cout << "\"Flurry Friends\" is $" << price1 << ":\n";
	cout << "\"Fiery Friends\" is $" << price2 << ":\n";
	
	cout.precision(2);
	cout << "\"Flurry Friends\" is $" << price1 << ":\n";
	cout << "\"Fiery Friends\" is $" << price2 << ":\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



