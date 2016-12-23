#include<iostream>
#include "test.h"
using namespace std;
typedef ios_base::fmtflags format;
typedef streamsize precis;
format setFormat();
void restore(format f, precis p);
Brass::Brass(const std::string & s, long num, double bal)
{
	fullname = s;
	acctNum = num;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		     << "deposit is canceled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amount must be positive; "
		<< "withdrawal canceled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		     << " exceeds your balance.\n"
		     << "Withdrawal canceled.\n";
	restore(initialState, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format intialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullname << endl;
	cout << "Client Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(intialState, prec);
}
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r):Brass(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r):Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct() const
{
	format intialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan rate: " << 100 * rate << "%\n";
	restore(intialState, prec);
}

void BrassPlus::Withdraw(double amt)
{
	format intialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction canceled.\n";
	restore(intialState, prec);
}

format setFormat()
{
	return cout.setf(ios_base::fixed,ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, ios_base::floatfield);
	cout.precision(p);
}
