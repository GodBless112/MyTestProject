#include <iostream>
using namespace std;
const int Max = 5;
double* fill_array(double *arr, int length);
void show_array(const double *arr, const double* end);
void revalue(double r, double *arr, double* end);

int main()
{
	double properties[Max];
	double* end = fill_array(properties, Max);
	show_array(properties, end);
	if (end > properties)
	{
		cout << "enter a factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number: ";
		}
		revalue(factor, properties, end);
		show_array(properties, end);
	}
	cout << "Done." << endl;
	cin.get();
	cin.get();
	while (1);
	return 0;
}
double* fill_array(double *arr, int n)
{
	double temp;
	double *pt;
	for (pt = arr; pt < arr+n; pt++)
	{
		cout << "enter value#" << (pt-arr)+1<< "\n";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input!\n";
			break;
		}
		else if (temp < 0)
			break;
		*pt = temp;
	}
	return pt;
}
void show_array(const double *arr, const double* end)
{
	const double *pt;
	for (pt = arr; pt < end; pt++)
	{
		cout << "Properties#" << (pt - arr)+1 << ": $";
		cout << *pt << endl;
	}
}
void revalue(double r, double *arr, double* end)
{
	double* pt;
	for (pt = arr; pt < end; pt++)
	{
		*pt *= r;
	}
}