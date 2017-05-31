#include<iostream>
#include "test.h"
using namespace std;

AcctABC::Formatting AcctABC::SetFormat() const
{
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void AcctABC::Restore(Formatting & f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}
void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; "
		<< "deposit is canceled.\n";
	else
		balance += amt;
}
void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

void Brass::Withdraw(double amt)
{
	Formatting f = SetFormat();
	if (amt < 0)
		cout << "Withdrawal amount must be positive; "
		<< "withdrawal canceled.\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt
		     << " exceeds your balance.\n"
		     << "Withdrawal canceled.\n";
	Restore(f);
}


void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Client: " << FullName() << endl;
	cout << "Client Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	Restore(f);
}
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r):AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Client: " << FullName() << endl;
	cout << "Client Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan rate: " << 100 * rate << "%\n";
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();
	double bal = Balance();
	if (amt <= bal)
		AcctABC::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction canceled.\n";
	Restore(f);
}


