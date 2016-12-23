﻿// static.cpp -- using a static local variable
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include "test.h"
// constants
// function prototype
template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) :cutoff(t) {}
	bool operator()(const T & v) { return v > cutoff; }
};
void outint(int n) { std::cout << n << " "; }

int main(void)
{
	using namespace std;
	TooBig<int> f100(100);
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));
	cout << "Trimmed lists:\n";
	for (auto x : yadayada)
		outint(x);
	cout << endl;
	for (auto x : etcetera)
		outint(x);
	cout << endl;
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


