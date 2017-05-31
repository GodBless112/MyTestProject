#include <iostream>
using namespace std;
int fac(int n);
int main()
{
	int n;
	cout << "enter a number:\n";
	while (cin >> n&&n >= 0)
	{
		cout << "enter a number:\n";
		cout << fac(n)<<endl;
	}
	while (1);
	return 0;
}
int fac(int n)
{
	int res=1;
	if (n > 1)
	{
		res = n*fac(n - 1);
	}
	else
		res = 1;
	return res;
}
