// static.cpp -- using a static local variable
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
#include "test.h"
// constants
// function prototype
using namespace std;
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) :hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n"; }
	virtual int Value() const{ return hold; }
};
class Superb :public Grand
{
public:
	Superb(int h = 0) :Grand(h) {}
	void Speak() const { cout << "I am a superb class!\n"; }
	virtual void Say() const { cout << "I hold the superb value of " << Value() << "!\n"; }
};
class Magnificant :public Superb
{
private:
	char ch;
public:
	Magnificant(int h = 0, char c = 'A') :Superb(h), ch(c) {}
	void Speak() const { cout << "I am a magnificant class!\n"; }
	void Say() const { cout << "I hold the character " << ch << " and the integer " << Value() << "!\n"; }
};

Grand * GetOne();
int main(void)
{
	srand(time(0));
	Grand * pg;
	Superb * ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << ".\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		if (typeid(Magnificant) == typeid(*pg))
			cout << "Yes, you're really magnificant.\n";
	}
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

Grand * GetOne()
{
	Grand * p = nullptr;
	switch (rand() % 3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificant(rand() % 100, 'A' + rand() % 26);
		break;
	}
	return p;
}
