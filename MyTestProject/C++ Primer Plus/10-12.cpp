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
	unsigned long  po;
	char ch;
	cout << "Please enter A to add a purchase order.\n";
	cout << "p to process a PO,or Q to quit\n";
	cout << "What are you ÅªÉ¶àÏ!\n";
	while (cin >> ch&&toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a':cout << "Enter aPO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "Stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':if (st.isempty())
			cout << "Stack already empty\n";
				 else 
				 {
					 st.pop(po);
					 cout << "PO #" << po << "poped\n";
				 }
				 break;
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

