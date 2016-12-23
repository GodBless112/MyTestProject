// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	string str;
	string name;
	double bal;
	cout << "请依次输入开户名，账号以及存放金额：\n";
	cin >> str; cin >> name; cin >> bal;
	BankAccount ba(str, name, bal);
	char ch;
	double cash;
	cout << "请输入你要进行的操作：D to deposit,W to withdraw,Q to quit\n";
	while (cin >> ch&&toupper(ch)!='Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'D':
		case 'd':
			cout << "Enter a cash number to deposit: ";
			cin >> cash;
			ba.deposit(cash);
			ba.show();
			break;
		case 'W':
		case 'w':
			cout << "Enter a cash number to withdraw: ";
			cin >> cash;
			ba.withdraw(cash);
			ba.show();
			break;
		}
		cout << "请输入你要进行的操作：D to deposit,W to withdraw,Q to quit\n";
	}
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
	continue;
	cin.get();
	
	return 0;
}

