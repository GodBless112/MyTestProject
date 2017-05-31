#include<iostream>
#include<string>
#include "test.h"
// constants
using namespace std;

// function prototype
long double sum_value() { return 0; }
template<class T>
long double sum_value(const T& value)
{
	return value;
}
template<class T,class... Args>
long double sum_value(const T& value, const Args&... args)
{
	return value + sum_value(args...);
}
int main(int argc, char* argv[])
{
	int a = 14;
	double b = 2.7;
	long y = 2000;
	char ch = 'c';
	cout << sum_value(a, b, y, ch) << endl;

	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


