#include <iostream>
using namespace std;
const int n1 = 5;
const int n2 = 1;
const int num1 = 47;
const int num2 = 27;
long double odds(unsigned num, unsigned n);
int main()
{
	double odds1 = odds(num1, n1);
	double odds2 = odds(num2, n2);
	cout << "中头奖的几率为： " << odds1*odds2 << endl;
	while (1);
	return 0;
}
long double odds(unsigned num, unsigned n)
{
	long double res = 1.0;
	for (num, n; n > 0; n--, num--)
		res = res*n / num;
	return res;
}
