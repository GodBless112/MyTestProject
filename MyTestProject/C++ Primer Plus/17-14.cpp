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
	char ch;
	while (cin.get(ch))
	{
		if (ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);
			break;
		}
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		exit(0);
	}
	while (cin.peek() != '#')
	{
		cin.get(ch);
		cout << ch;
	}
	if(!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		exit(0);
	}
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	
		continue;
	cin.get();

	return 0;
}



