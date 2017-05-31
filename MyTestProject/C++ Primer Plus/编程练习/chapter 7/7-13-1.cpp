#include <iostream>
#include<cmath>
double result(int a, int b);
int main()
{
	using namespace std;
	int a, b;
	cout << "Please enter two number:\n";
	while (cin >> a >> b&&a != 0 && b != 0)
	{
		cout << "result: " << result(a, b) << endl;
		cout << "Enter next two number:\n";
	}
	cout << "Good Bye!\n";
	while (1);
	return 0;
}
double result(int a, int b)
{
	double value = (double)2.0*a*b / (a + b);
	return value;
}