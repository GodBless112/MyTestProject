﻿// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include "test.h"
// constants
const int ArSize = 10;
const int MaxLen = 81;
// function prototype
using std::cout;
using std::cin;
using std::endl;
int main()
{
	String name;
	cout << "Hi, what's your mame?\n>> ";
	cin >> name;

	cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin&&cin.get()!='\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		//use pointers to keeptrack of shortest, first strings
		String * shortest = &sayings[0];
		String * first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String *favorite = new String(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
		cout << "This program used " << String::HowMany() << "String objects.Bye.\n";
	}
	else
		cout << "No input.Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void callme1(String & rsb)
{
	cout << "String passed by reference:\n";
	cout << "    \"" << rsb << "\"\n";
}
void callme2(String sb)
{
	cout << "String passed by value:\n";
	cout << "    \"" << sb << "\"\n";
}