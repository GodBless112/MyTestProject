#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
T max5(T arr[], int n);
template <> const char* max5<const char*>(const char* arr[], int n);
int main()
{
	int a[6] = { 1,2,3,4,6,5 };
	cout << max5(a,6) << endl;
	double b[5] = { 0.1,0.2,0.3,0.4};
	cout << max5(b,3) << endl;
	const char * char_arr[5] = {
		"hello world!",
		"what your name?",
		"I love you",
		"you are wonderful",
		"hi"
	};
	cout << max5(char_arr, 5) << endl;
	while (1);
	return 0;
}
template <typename T>
T max5(T arr[], int n)
{
	T temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}
template <> const char* max5<const char*>(const char* arr[], int n)
{
	const char* temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (strlen(arr[i]) > strlen(temp))
			temp = arr[i];
	}
	return temp;
}