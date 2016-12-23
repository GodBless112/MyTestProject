// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
#include<cctype>
// constants
// function prototype
using namespace std;
int main(void)
{
	Stack<string> st;
	char ch;
	string po;
	cout << "Please enter A to add a purchase order.\n"
		<< "P to process a PO, or Q to qiut.\n";
	while (cin >> ch&&toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "Stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "Stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO #" << po << " poped\n";
				break;
			}
		}
		cout << "Pleaasae enter A to add purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye.\n";
	return 0;
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


