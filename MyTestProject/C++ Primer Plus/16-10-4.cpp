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
int reduce(long ar[], int n);
void Show(long n) { cout << n << " "; }

int main(void)
{
	long ar[10] = { 1,1,2,2,3,3,4,4,5,5 };
	cout << reduce(ar, 10) << endl;

	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

//int reduce(long ar[], int n)
//{
//	if (n == 0)
//		return 0;
//	else
//	{
//		sort(ar, ar + n);
//		long* pr=unique(ar, ar + n);
//		return pr - ar;
//	}
//}
int reduce(long ar[], int n)
{
	list<long> arr(ar, ar + n);
	arr.sort();
	arr.unique();
	//copy(arr.begin(), arr.end(), ostream_iterator<long,char>(cout, " "));
	for (auto x : arr)
		Show(x);
	cout << endl;
	return arr.size();
}
