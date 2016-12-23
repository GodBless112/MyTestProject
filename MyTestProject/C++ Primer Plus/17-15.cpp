// static.cpp -- using a static local variable
#include<iostream>
#include<iomanip>
#include<cmath>
#include<exception>
#include "test.h"
// constants
const int SLEN = 10;
// function prototype
inline void eatline() { while (std::cin.get() != '\n') continue; }
using namespace std;

int main(void)
{
	char name[SLEN];
	char title[SLEN];
	cout << "Enter your name: ";
	cin.get(name, SLEN);
	if (cin.peek() != '\n')
		cout << "Sorry, we only have enough room for "
		<< name << endl;
	eatline();
	cout << "Dear " << name << ", enter your title.\n";
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
		cout << "We were forced to truncate your title.\n";
	eatline();
	cout << "Name: " << name
		<< "\nTitle: " << title << endl;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	
		continue;
	cin.get();

	return 0;
}



