#include <iostream>
using namespace std;
const int ArSize = 80;
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 2);
int gety(int a);
int main()
{
	char trip[ArSize];
	unsigned long n;
	cout << "Enter a string:" << endl;
	cin.getline(trip, ArSize);
	cout << "Enter a number:" << endl;
	cin>>n;
	char *temp;
	for (int i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}

	while (1);
	return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits >= ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else
		return num;
}
char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char *p = new char[n + 1];
	int i;
	for (i = 0; i < n&&str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}
