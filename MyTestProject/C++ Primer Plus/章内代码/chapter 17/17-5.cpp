// static.cpp -- using a static local variable
#include<iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	cout.fill('*');
	const char * staff[2] = { "Waldo Whipsnade","Wilmarie Wooper" };
	long bonus[2] = { 900,1350 };
	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << endl;
	}
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



