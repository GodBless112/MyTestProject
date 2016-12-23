// static.cpp -- using a static local variable
#include <iostream>
#include<cstring>
#include "test.h"
#include<vector>
// constants
// function prototype
const int SIZE = 5;
using namespace std;
int main(void)
{
	Worker * lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter   s: singer   "
			<< "t: singing waiter   q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w,s,t,or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': lolas[ct] = new Waiter;
			break;
		case 's': lolas[ct] = new Singer;
			break;
		case 't': lolas[ct] = new SingingWaiter;
			break;
		default:
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


