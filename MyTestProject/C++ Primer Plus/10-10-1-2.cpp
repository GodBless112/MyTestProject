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
		std::cout << "ûǮ������";
}
void BankAccount::withdraw(double money)
{
	if (money < 0)
		std::cout << "�Ǻ���\n";
	else if (balance >= money)
		balance -= money;
	else
		std::cout << "����˰�\n";
}
void BankAccount::show() const
{
	std::cout << "�û���: " << name << std::endl;
	std::cout << "�� �ţ� " << accountnum << std::endl;
	std::cout << "�� ��: " << balance << std::endl;
}