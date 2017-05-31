// static.cpp -- using a static local variable
#include<iostream>
#include<iomanip>
#include<cmath>
#include<exception>
#include "test.h"
// constants
// function prototype
using namespace std;
const int Limit = 255;
int main(void)
{
	char input[Limit];
	cout << "Enter a string for getline() processing:\n";
	cin.getline(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 1\n";
	char ch;
	cin.get(ch);
	cout << "The next input character is "<<ch << endl;
	if (ch != '\n')
		cin.ignore(Limit, '\n');
	cout << "Enter a string for get() processing:\n";
	cin.get(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";
	cin.get(ch);
	cout << "The next input character is " << ch << endl;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



