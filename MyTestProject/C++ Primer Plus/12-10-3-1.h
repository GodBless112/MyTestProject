#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
class Stock
{
private:
	char * company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char *co, long n = 0, double pr = 0);
	Stock(const Stock & s);
	~Stock();
	Stock & operator=(const Stock & s);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	friend std::ostream & operator<<(std::ostream &os, const Stock & s);
	const Stock & topval(const Stock & s) const;
};

#endif // !TEST_H_
