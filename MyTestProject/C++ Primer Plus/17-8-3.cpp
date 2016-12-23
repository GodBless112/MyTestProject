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
	ofstream fout(argv[2], ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Could not open the outpuflie " << argv[2] << endl;
		exit(EXIT_FAILURE);
	}
	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cerr << "Could not open the inputfile " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Here are the current contents of the file " << argv[1] << ": " << endl;
	char ch;
	while (fin.get(ch))
	{	
		cout << ch;
		fout << ch;
	}
	fin.close();
	fout.close();
	cout << "Done.\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



