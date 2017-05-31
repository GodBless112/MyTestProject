// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<memory>
#include "test.h"
// constants
// function prototype
using namespace std;
class Report
{
private:
	string str;
public:
	Report(const string s):str(s)
		{cout << "Object created!\n";}
	~Report() { cout << "Object deleted!\n"; }
	void comment() const { cout << str << "\n"; }
};
int main(void)
{
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}

	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}



