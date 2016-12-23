#pragma once
#ifndef TEST_H_
#define TEST_H_
#include <string>
using std::string;
class BankAccount
{
private:
	string name;
	string accountnum;
	double balance;
public:
	BankAccount(const string & client,const string & num, double money=0.0);
	void show() const;
	void deposit(double money);
	void withdraw(double money);
};
#endif // !TEST_H_
