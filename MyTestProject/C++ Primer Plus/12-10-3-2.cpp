#include <iostream>
#include "test.h"

Stock::Stock()
{
	std::cout << "Default constructor called\n";
	company = new char[1];
	company[0] = '\0';
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char * co, long n, double pr)
{
	std::cout << "Constructor called\n";
	company = new char[strlen(co) + 1];
	strcpy_s(company, strlen(co) + 1, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative;" << company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::Stock(const Stock & s)
{
	std::cout << "Copy constructor called\n";
	company = new char[strlen(s.company) + 1];
	strcpy_s(company, strlen(s.company) + 1, s.company);
	
	shares = s.shares;
	share_val = s.share_val;
	set_tot();
}
Stock::~Stock()
{
	delete[] company;
	std::cout << "Bye, " << company << "!\n";
}
Stock & Stock::operator=(const Stock & s)
{
	// TODO: 在此处插入 return 语句
	if (this == &s)
		return *this;
	std::cout << "Assignment constructor called\n";
	delete[] company;
	company = new char[strlen(s.company) + 1];
	strcpy_s(company, strlen(s.company) + 1, s.company);

	shares = s.shares;
	share_val = s.share_val;
	set_tot();
	return *this;

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

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	// TODO: 在此处插入 return 语句
	using std::ios_base;
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);
	os << "Company: " << s.company
	   << " Shares: " << s.shares << std::endl;
	os << " Share Price: " << s.share_val;
	os.precision(2);
	os << " Total Worth: $" << s.total_val << std::endl;
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}