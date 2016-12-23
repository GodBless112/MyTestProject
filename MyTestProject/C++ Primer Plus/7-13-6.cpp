#include <iostream>
using namespace std;
int fill_array(double *arr, int length);
void show_array(double *arr, int length);
void reverse_array(double *arr, int length);

int main()
{
	int n;
	cout << "enter a number:\n";
	cin >> n;
	double *arr=new double[n];
	int length = fill_array(arr, n);
	show_array(arr, length);
	reverse_array(arr, length);
	cout << "翻转后结果：\n";
	show_array(arr, length);
	while (1);
	delete[]arr;
	return 0;
}
int fill_array(double *arr, int n)
{
	int i=0;
	double temp;
	for (i = 0; i < n; i++)
	{
		cout << "enter value#" << i + 1 << "\n";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			cout << "bad input!\n";
			break;
		}
		else
			arr[i] = temp;
	}
	return i;
}
void show_array(double *arr, int length)
{
	for (int i = 0; i < length; i++)
	cout << "arr_res" << i + 1 <<": "<< arr[i] << endl;
}
void reverse_array(double *arr, int length)
{
	int i, j;
	for (i = 0, j = length - 1 - i; i < j; i++, j--)
	{
		double temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}