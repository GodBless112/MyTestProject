// static.cpp -- using a static local variable
#include<iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Eupgoria";
	int len = strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}
	cout << "Decreasing loop index:\n";
	for (i = len; i > 0; i--)
	{
		cout.write(state2, i) << endl;
	}
	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;
	long val = 560031841;
	cout.write((char *)&val, sizeof(long));
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



