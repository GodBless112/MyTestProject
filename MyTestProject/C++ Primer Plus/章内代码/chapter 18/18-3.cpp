#include<iostream>
#include<utility>
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
	Useless &operator=(const Useless &f);
	Useless &operator=(Useless &&f);
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
}
Useless::Useless(int k) :n(k)
{
	++ct;
	pc = new char[n];
}
Useless::Useless(int k, char ch) :n(k)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = ch;
}
Useless::Useless(const Useless & f) :n(f.n)
{
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = f.pc[i];
}
Useless::Useless(Useless && f) :n(f.n)
{
	++ct;
	pc = f.pc;		//steal adress
	f.pc = nullptr;	//give old object nothing in return
	f.n = 0;
}
Useless::~Useless()
{
	delete [] pc;
}
Useless Useless::operator+(const Useless & f) const
{
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; ++i)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; ++i)
		temp.pc[i] = f.pc[i - n];
	return temp;
}
Useless & Useless::operator=(const Useless & f)
{
	// TODO: 在此处插入 return 语句
	cout << "copy assigment operator called:\n";
	if (this == &f)
		return *this;
	delete[]pc;
	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; ++i)
		pc[i] = f.pc[i];
	return *this;
}
Useless & Useless::operator=(Useless && f)
{
	// TODO: 在此处插入 return 语句
	cout << "move assignment operator called:\n";
	if (this == &f)
		return *this;
	delete[]pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
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
		Useless two = one + one;		//调用移动构造函数
		cout << "Object one: ";
		one.ShowData();
		cout << "Object two: ";
		two.ShowData();
		Useless three, four;
		cout << "three = one\n";
		three = one;
		cout << "Now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two;				//自动移动赋值
		cout << "now object four = ";
		four.ShowData();
		cout << "four = move(one)\n";
		four = move(one);				//强制移动赋值
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();
	}
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


