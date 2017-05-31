#include <iostream>
using namespace std;
double add(double x, double y);
double sub(double x, double y);
double mean(double x, double y);
double calculate(double x, double y, double (*pf)(double, double));
int main()
{
	double(*pf[3])(double,double) = {add,sub,mean};
	const char(*guggle[3]) = { "sum","difference","mean" };
	double a, b;
	cout << "Enter two numbers: (q to quit)"<<endl;
	int i;
	while (cin >> a >> b)
	{
		cout << calculate(a, b, add) << "=sum"<<endl;
		cout << calculate(a, b, mean) << "=mean"<<endl;
		for (i = 0; i < 3; i++)
		{
			cout << calculate(a, b, pf[i]) << " = " << guggle[i] << endl;
		}
	}
	while (1);
	return 0;
}
double calculate(double x, double y, double(*pf)(double, double))
{
	return pf(x, y);
}
double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mean(double x, double y)
{
	return (x + y) / 2.0;
}