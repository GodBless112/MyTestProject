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

int main()
{
	string infile1 = "test1.txt", infile2 = "test2.txt";
	string outfile = "test3.txt";
	ifstream fin1(infile1.c_str()), fin2(infile2.c_str());
	ofstream fout(outfile.c_str());
	if (!fin1.is_open() || !fin2.is_open())
	{
		cerr << "Can't open file1 " << infile1 << " or file2 " << infile2 << endl;
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open())
	{
		cerr << "Can't open file3 " << outfile << endl;
		exit(EXIT_FAILURE);
	}
	string temp1, temp2;
	while (!fin1.eof() && !fin2.eof())
	{
		getline(fin1, temp1);
		getline(fin2, temp2);
		cout << "file1: " << temp1 << " " << "file2: " << temp2 << endl;
		fout << temp1 << " " << temp2 << endl;
	}
	while (!fin1.eof())
	{
		getline(fin1, temp1);
		cout << "morefile1: " << temp1 << endl;
		fout << temp1 << endl;
	}
	while (!fin2.eof())
	{
		getline(fin2, temp2);
		cout << "more file2: " << temp2 << endl;
		fout << temp2 << endl;
	}
	
	
	cout << "Done.\n";
	
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



