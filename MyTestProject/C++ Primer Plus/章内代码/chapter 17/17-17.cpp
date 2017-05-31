// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include "test.h"
// constants

// function prototype

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}
	ifstream fin;
	long count;
	long total = 0;
	char ch;
	for (int file = 1; file < argc; file++)
	{
		fin.open(argv[file]);
		if (!fin.is_open())
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))
			count++;
		cout << count << " characters in " << argv[file] << endl;
		total += count;
		fin.clear();
		fin.close();
	}
	cout << total << " charcters in all files\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



