#include<iostream>
#include<initializer_list>
#include "test.h"
// constants
using namespace std;

// function prototype
template<class T>
T average_list(initializer_list<T> il) 
{
	T sum = 0;
	int i = 0;
	for (auto start = il.begin(); start != il.end(); start++, i++)
		sum += *start;
	return sum / i;
}
int main(int argc, char* argv[])
{
	auto q = average_list({ 15.4,10.7,9.0 });
	cout << q << endl;
	cout << average_list({ 20,30,19,17,45,38 }) << endl;
	auto ad = average_list<double>({ 'A', 70, 65, 33 });
	cout << ad << endl;
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


