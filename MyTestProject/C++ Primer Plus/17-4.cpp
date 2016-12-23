// static.cpp -- using a static local variable
#include<iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	int w = cout.width(30);
	cout << "default field width = " << w << ":\n";
	cout.width(5);
	cout << "N" << ":";
	cout.width(8);
	cout << "N * N" << ":\n";
	for (long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i << ":";
		cout.width(8);
		cout << i*i << ":\n";
	}
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



