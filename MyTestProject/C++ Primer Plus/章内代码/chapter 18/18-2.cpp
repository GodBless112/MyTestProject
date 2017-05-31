#include<iostream>
#include "test.h"
// constants
using namespace std;
// function prototype
class Useless
{
private:
	int n;			//nuber of element
	char *pc;		//pointer of data
	static int ct;	//number of object
	void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless &f);	//regular copy constructor
	Useless(Useless &&f);		//move constructer
	~Useless();
	Useless operator+(const Useless & f) const;
	void ShowData() const;
};
int Useless::ct = 0;
void Useless::ShowObject() const
{
	cout << "Number of element: " << n;
	cout << " Data address: " << (void *)pc << endl;
}
Useless::Useless()
{
	++ct;
	n = 0; 
	pc == nullptr;
	cout << "default constructor called; number of objects: " << ct << endl;
	ShowObject();
}
Useless::Useless(int k) :n(k)
{
	++ct;
	cout << "int constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	ShowObject();
}
Useless::Useless(int k, char ch) :n(k)
{
	++ct;
	cout << "int, char constructor called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = ch;
	ShowObject();
}
Useless::Useless(const Useless & f) :n(f.n)
{
	++ct;
	cout << "copy const called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = f.pc[i];
	ShowObject();
}
Useless::Useless(Useless && f) :n(f.n)
{
	++ct;
	cout << "move constructor called; number of objects: " << ct << endl;
	pc = f.pc;		//steal adress
	f.pc = nullptr;	//give old object nothing in return
	f.n = 0;
	ShowObject();
}
Useless::~Useless()
{
	cout << "destructor called; number of objects left: " << --ct << endl;
	cout << "deleted object:\n";
	ShowObject();
	delete [] pc;
}
Useless Useless::operator+(const Useless & f) const
{
	cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; ++i)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; ++i)
		temp.pc[i] = f.pc[i - n];
	cout << "temp object:\n";
	cout << "Leaving operator+()\n";
	return temp;
}
void Useless::ShowData() const
{
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; ++i)
			cout << pc[i];
	cout << endl;
}
int main(int argc, char* argv[])
{
	{
		Useless one(10, 'x');
		Useless two = one;		//调用复制构造函数
		Useless three(20, 'o');
		Useless four(one + three);	//调用+和移动
		cout << "Object one: ";
		one.ShowData();
		cout << "Object two: ";
		two.ShowData();
		cout << "Object three: ";
		three.ShowData();
		cout << "Object four: ";
		four.ShowData();
	}
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


