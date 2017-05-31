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
	QueueTP<Worker *> lolas(SIZE);
	Worker * temp;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the command:\n"
			<< "A or a to add a item to queue:\n"
			<< "P or p to delete a item from queue:\n"
			<< "Q or q to quit.\n";
		cin >> choice;
		while (strchr("apq", tolower(choice)) == NULL)
		{
			cout << "Please enter a A,a,P,p,Q,or q: ";
			cin >> choice;
		}
		if (tolower(choice) == 'q')
			break;
		switch (tolower(choice))
		{
		case 'a': 
			temp = new Worker;
			cin.get();
			temp->Set();
			if (lolas.isfull())
				cout << "Queue is already full.\n";
			else
				lolas.enqueue(temp);
			break;
		case 'p': 
			if (lolas.isempty())
				cout << "Queue is already empty.\n";
			else
			{
				lolas.dequeue(temp);
				temp->Show();
			}
				
			break;
		default:
			break;
		}
	}
	cout << "\nHere are the total count:\n";
	cout << lolas.queuecount()<<endl;

	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


