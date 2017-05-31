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

int main(int argc,char * argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ofstream fout(argv[1], ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Could not open " << argv[1] << endl;
		fout.clear();
	}
	cout << "Please enter a string: ";
	char ch;
	while (cin.get(ch))
	{
		if (ch != '\n')
			fout << ch;
		else
			break;
	}
	fout.close();
	cout << "Done.\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



