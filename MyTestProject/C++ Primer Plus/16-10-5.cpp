// static.cpp -- using a static local variable
#include<iostream>
#include<string>
#include<list>
#include<iterator>
#include<cstdlib>
#include<algorithm>
#include<cctype>
#include "test.h"
// constants
// function prototype
using namespace std;
template<class T>
int reduce(T ar[], int n);
template<class T>
void Show(T n) { cout << n << " "; }

int main(void)
{
	long ar[10] = { 1,1,2,2,3,3,4,4,5,5 };
	cout << reduce(ar, 10) << endl;
	string strar[10] = { "aa","aa","bb","bb","cc","cc","dd","dd","ee","ee" };
	cout << reduce(strar, 10) << endl;
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
template<class T>
int reduce(T ar[], int n)
{
	if (n == 0)
		return 0;
	else
	{
		sort(ar, ar + n);
		T* pr=unique(ar, ar + n);
		copy(ar, pr, ostream_iterator<T, char>(cout, " "));
		cout << endl;
		return pr - ar;
	}
}
//template<class T>
//int reduce(T ar[], int n)
//{
//	list<T> arr(ar, ar + n);
//	arr.sort();
//	arr.unique();
//	//copy(arr.begin(), arr.end(), ostream_iterator<T,char>(cout, " "));
//	for (auto x : arr)
//		Show(x);
//	cout << endl;
//	return arr.size();
//}
