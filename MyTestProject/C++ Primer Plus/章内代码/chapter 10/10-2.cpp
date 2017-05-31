#include <iostream>
#include "test.h"

void Stock::acquires(const std::string &co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative;"
			<< company << "shares set to 0!" << std::endl;
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares can't be negative;"
			<< company << "Transaction is aborted!" << std::endl;
	}
	else
	{

		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares can't be negative;"
			<< company << "Transaction is aborted!" << std::endl;
	}
	else if (num>shares)
	{
		std::cout << "You can't sell more than you have;"
			<< company << "Transaction is aborted!" << std::endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
void Stock::show()
{
	using std::cout;
	using std::endl;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company: " << company
		<< " Shares: " << shares << endl;
	cout << " Share Price: " << share_val;
	cout.precision(2);
	cout << " Total Worth: $" << total_val << endl;
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}