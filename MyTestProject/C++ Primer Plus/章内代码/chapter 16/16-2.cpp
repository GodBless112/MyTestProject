// static.cpp -- using a static local variable
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	ifstream fin;
	fin.open("test.txt");
	if (fin.is_open() == false)
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();

	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



