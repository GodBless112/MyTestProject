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
const char * file = "test.txt";
// function prototype

using namespace std;

int main(void)
{
	char ch;
	ifstream fin;
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< file << " file:\n";
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



