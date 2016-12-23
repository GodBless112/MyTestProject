// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
using namespace std;
// constants
template<template<typename T> class Thing>
class Crab
{
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	bool push(int a, double b) { return s1.push(a) && s2.push(b); }
	bool pop(int & a, double & b) { return s1.pop(a) && s2.pop(b); }
};
// function prototype

int main(void)
{
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
	while (cin >> ni >> nb&&ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}
	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


