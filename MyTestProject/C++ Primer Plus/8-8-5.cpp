#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
T max5(T arr[5]);
int main()
{
	int a[5] = { 1,2,3,4,5 };
	cout << max5(a) << endl;
	double b[5] = { 0.1,0.2,0.3,0.4,0.5 };
	cout << max5(b) << endl;
	while (1);
	return 0;
}
template <typename T>
T max5(T arr[5])
{
	T temp = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}