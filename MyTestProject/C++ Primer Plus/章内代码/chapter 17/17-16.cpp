// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<fstream>
#include "test.h"
// constants

// function prototype

using namespace std;

int main(void)
{
	string filename;
	cout << "Enter name for new file: ";
	cin >> filename;
	ofstream fout(filename.c_str());
	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();

	ifstream fin(filename.c_str());
	if (!cin.is_open())
		cerr << "Error!\n";
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done.\n";
	fin.close();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	
		continue;
	cin.get();

	return 0;
}



