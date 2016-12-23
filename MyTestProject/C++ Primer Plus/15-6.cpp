// static.cpp -- using a static local variable
#include <string>
#include<iostream>
#include "test.h"
// constants
// function prototype
using namespace std;
int main(void)
{
	QueneTP<string> cs(5);
	string temp;
	while (!cs.isfull())
	{
		cout << "Please enter your name. You will be "
				"served in the order of arrival.\n"
				"name: ";
		getline(cin, temp);
		cs.enquene(temp);
	}
	cout << "The quene is full. Processing begins!\n";
	while (!cs.isempty())
	{
		cs.dequene(temp);
		cout << "Now processing " << temp << "...\n";
	}
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


