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
	string lit = "It was a dark and stormy day, and "
			" the full moon glowed brilliantly. ";
	istringstream instr(lit);
	cout << lit;
	string word;
	while (instr >> word)
		cout << word << endl;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



