#include<iostream>
#include<string>
#include "test.h"
// constants
using namespace std;
const long Size1 = 390000L;
// function prototype
void show_list3() {}
template<typename T ,typename... Args>
void show_list3(T value, Args... args)
{
	cout << value << ", ";
	show_list3(args...);
}
int main(int argc, char* argv[])
{
	int n = 13;
	double x = 2.71828;
	string mr = "Mr.string objects!";
	show_list3(n, x);
	show_list3(x*x, '!', 7, mr);
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


