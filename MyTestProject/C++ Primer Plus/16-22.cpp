// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<initializer_list>
#include<algorithm>
#include<cstdlib>
#include "test.h"
// constants
// function prototype
using namespace std;
double sum(initializer_list<double> i);
double average(const initializer_list<double> & ri1);
int main(void)
{
	cout << "List 1: sum = " << sum({ 2,3,4 })
		<< ", ave = " << average({ 2,3,4 }) << endl;
	initializer_list<double> d1 = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "List 2: sum = " << sum(d1)
		<< ", ave = " << average(d1) << endl;
	d1 = { 16.0,25.0,36.0,40.0,64.0 };
	cout << "List 3: sum = " << sum(d1)
		<< ", ave = " << average(d1) << endl;
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


double sum(initializer_list<double> i)
{
	double tot = 0;
	for (auto p = i.begin(); p != i.end(); p++)
		tot += *p;
	return tot;
}

double average(const initializer_list<double>& ri1)
{
	double tot = 0;
	int n = ri1.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto p = ri1.begin(); p != ri1.end(); p++)
			tot += *p;
		ave = tot / n;
	}
	return ave;
}
