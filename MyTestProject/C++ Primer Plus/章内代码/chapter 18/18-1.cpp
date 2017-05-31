#include<iostream>
#include "test.h"
// constants
using namespace std;
// function prototype
inline double f(double tf) { return 5.0*(tf - 32.0) / 9.0; }
int main(int argc, char* argv[])
{
	double tc = 21.5;
	double &&rd1 = 7.07;
	double &&rd2 = 1.8*tc + 32.0;
	double &&rd3 = f(rd2);
	cout << "tc value and adress: " << tc << ", " << &tc << endl;
	cout << "rd1 value and adress: " << rd1 << ", " << &rd1 << endl;
	cout << "rd2 value and adress: " << rd2 << ", " << &rd2 << endl;
	cout << "rd3 value and adress: " << rd3 << ", " << &rd3 << endl;
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


