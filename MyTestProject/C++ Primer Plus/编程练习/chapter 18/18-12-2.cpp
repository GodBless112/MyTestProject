#include<iostream>
#include<string>
#include "test.h"
// constants
using namespace std;

// function prototype
class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info *pi;
public:
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv &cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv &cp);
	Cpmv & operator=(Cpmv && mv);
	Cpmv operator+(const Cpmv &obj) const;
	void Display() const;
};
int main(int argc, char* argv[])
{
	{
		Cpmv zero, one("one", "one");
		cout << "Object zero: ";
		zero.Display();
		cout << "Object one: ";
		one.Display();
		Cpmv two = one + one;
		cout << "Object two: ";
		two.Display();
		Cpmv three, four;
		cout << "three = one: ";
		three = one;
		cout << "Now object three = ";
		three.Display();
		cout << "and object one="; 
		one.Display();
		cout << "four = one + two\n"; 
		four = one + two;
		cout << "now object four ="; 
		four.Display();
		cout << "four = move(one)\n"; 
		four = move(one);
		cout << "now object four="; 
		four.Display();
		cout << "and object one="; 
		one.Display();
	}
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}

Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "Nothing";
	pi->zcode = "Nothing";
	cout << "Default constructor called!\n";
	Display();
}

Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "String string constructor called!\n";
	Display();
}

Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	cout << "Copy constructor called!\n";
	Display();
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
	cout << "Move constructor called!\n";
	Display();
}

Cpmv::~Cpmv()
{
	delete pi;
	cout << "Destructor called|\n";
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	// TODO: 在此处插入 return 语句
	cout << "Copy assignment called!\n";
	if (&cp == this)
		return *this;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	Display();
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	// TODO: 在此处插入 return 语句
	cout << "Move assignment called!\n";
	if (&mv == this)
		return *this;
	pi = mv.pi;
	mv.pi = nullptr;
	Display();
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	cout << "Entering operator+\n";
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	cout << "Leaving operator+\n";
	return temp;
}

void Cpmv::Display() const
{
	if (nullptr == pi)
	{
		cout << "Empty Info!\n";
		return;
	}
	cout << pi->qcode << ", ";
	cout << pi->zcode << endl;
}
