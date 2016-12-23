// static.cpp -- using a static local variable
#include <iostream>
#include<cstring>
#include "test.h"
// constants
// function prototype
const int SIZE = 5;
using namespace std;
int main(void)
{
	Person * per[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Please enter a person type:\n"
			<< "G/g for Gunslinger\t" << "P/p for PokerPlayer\n"
			<< "B/b for BadDude\t" << "\tQ/q for quit\n";
		cin >> choice;
		while (strchr("GPBQ", toupper(choice))==NULL)
		{
			cout << "Please enter a G/g, P/p, B/b, or Q/q\n";
			cin >> choice;
		}
		if (toupper(choice) == 'Q')
			break;
		switch (toupper(choice))
		{
		case 'G':
			per[ct] = new Gunslinger;
			break;
		case'P':
			per[ct] = new PokerPlayer;
			break;
		case'B':
			per[ct] = new BadDude;
		}
		cin.get();
		per[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		per[i]->Show();
	}
	for (i = 0; i < ct; i++)
	{
		delete per[i];
	}
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


