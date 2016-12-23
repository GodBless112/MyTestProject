#include <iostream>
#include "test.h"
using std::string;
BankAccount::BankAccount(const string & client, const string & num, double money)
{
	name = client;
	accountnum = num;
	balance = money;
}
void BankAccount::deposit(double money)
{
	if (money >= 0)
		balance += money;
	else
		std::cout << "没钱你存个蛋";
}
void BankAccount::withdraw(double money)
{
	if (money < 0)
		std::cout << "呵呵了\n";
	else if (balance >= money)
		balance -= money;
	else
		std::cout << "想多了吧\n";
}
void BankAccount::show() const
{
	std::cout << "用户名: " << name << std::endl;
	std::cout << "账 号： " << accountnum << std::endl;
	std::cout << "余 额: " << balance << std::endl;
}