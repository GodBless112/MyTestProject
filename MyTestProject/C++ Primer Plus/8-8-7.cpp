#include <iostream>
using namespace std;
template <typename T>
T SumArray(T arr[], int n);
template <typename T>
T SumArray(T * arr[], int n);
struct debts
{
	char name[50];
	double amount;
};

int main()
{
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe",2400.0 },
		{ "Ura Foxe",1300.0 },
		{ "Iby Stout",1800.0 }
	};
	double * pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "Listing Mr.E's counts of tings:\n";
	cout<<SumArray(things, 6)<<endl;
	cout << "Listing Mr.E's debts:\n";
	cout<<SumArray(pd, 3)<<endl;

	while (1);
	return 0;
}
template <typename T>
T SumArray(T arr[], int n)
{
	cout << "template A\n";
	T temp=(T)0;
	for (int i = 0; i < n; i++)
	{
		temp += arr[i];
	}
	cout << endl;
	return temp;
}
template <typename T>
T SumArray(T * arr[], int n)
{
	cout << "template B\n";
	T temp = (T)0;
	for (int i = 0; i < n; i++)
	{
		temp += *arr[i];
	}
	cout << endl;
	return temp;
}