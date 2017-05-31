#include<iostream>
#include "test.h"
// constants
using namespace std;
const long Size1 = 390000L;
// function prototype
double dub(double x) { return 2.0*x; }
double square(double x) { return x*x; }
int main(int argc, char* argv[])
{
	double y = 1.21;
	cout << "Function pointer dub:\n";
	cout << " " << use_f(y, dub) << endl;
	cout << "Function pointer square:\n";
	cout << " " << use_f(y, square) << endl;
	cout << "Function object Fp:\n";
	cout << " " << use_f(y, Fp(5.0)) << endl;
	cout << "Function object Fq:\n";
	cout << " " << use_f(y, Fq(5.0)) << endl;
	cout << "lambda expression 1:\n";
	cout << " " << use_f(y, [](double u) { return u*u; }) << endl;
	cout << "lambda expression 2:\n";
	cout << " " << use_f(y, [](double u) { return u+u/2.0; }) << endl;
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}


