// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	Stack st;
	customer  cc;
	int sum = 0;
	char ch;
	cout << "Please enter A to add a purchase order.\n";
	cout << "p to process a PO,or Q to quit\n";
	while ((cin >> ch)&&toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		cout << ch;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':cout << "Enter a Item name and number to add: ";
			cin.getline(cc.fullname, 25);
			cin >> cc.payment;
			if (st.isfull())
				cout << "Stack already full\n";
			else
				st.push(cc);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "Stack already empty\n";
			else
			{
				st.pop(cc);
				sum += cc.payment;
				cout << "PO #" << cc.fullname<<"   "<<cc.payment << "poped\n";
			}
			break;
		default:
			cout << "wrong";
		}
		cout << "Please enter A to add purchase order,\n"
			<< "P to process a PO,or Q to quit:\n";
	}
	cout << "BYE\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

