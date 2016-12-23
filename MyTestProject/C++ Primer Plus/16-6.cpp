// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<memory>
#include "test.h"
// constants
// function prototype
using namespace std;

int main(void)
{
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Error")),
		auto_ptr<string>(new string("Goose Eggs")),
	};
	auto_ptr<string> pwin;
	pwin = films[2];

	cout << "The nominees for best aviab baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;
	cout << "The winner is " << *pwin << "!\n";

	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



