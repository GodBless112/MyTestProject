// static.cpp -- using a static local variable
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include "test.h"
// constants

// function prototype

using namespace std;

int main(void)
{
	/*char ch;
	int ct = 0;
	cout << "Enter a string to count (# means end): ";
	cin.get(ch);
	while (ch != '#'&&ch != '\t'&&ch != '\n')
	{
		if(ch!=' ')
			ct++;
		cin.get(ch);
	}
	cin.putback(ch);
	cout << "ct = " << ct;*/
	char ch;
	int ct = 0;
	cout << "Enter a string to count (# means end): ";
	cin >> ch;
	while (ch != '#')
	{
		ct++;
		cin.get(ch);	
	}
	cin.putback(ch);
	cout << "ct = " << ct;
	cin >> ch;
	cout << ch;
	cout << "Done.\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



