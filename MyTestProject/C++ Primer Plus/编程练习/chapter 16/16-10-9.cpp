// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<list>
#include "test.h"
// constants
const int test_time = 10000000;
// function prototype
using namespace std;
void Show(const string & s) { cout << s << " "; }
int main()
{
	srand(time(0));
	vector<int> vi0;
	for (int i = 0; i < test_time; i++)
		vi0.push_back(rand()%test_time);
	vector<int> vi(vi0);
	list<int> li(vi0.begin(), vi0.end());
	double vector_sort_vi_time, list_sort_li_time;
	time_t start, end;
	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	cout << "The time of vector sort: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	start = clock();
	li.sort();
	end = clock();
	cout << "The time of list sort: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	copy(vi0.begin(), vi0.end(), li.begin());

	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "The time of list sort 2: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


