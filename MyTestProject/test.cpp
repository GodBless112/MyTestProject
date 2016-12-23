///桶排序
//线性时间排序，时间复杂度为O(n)=n+(nlogn-nlogr)，r为桶的大小
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#include<iterator>
#include<unordered_map>
#include<Windows.h>
#include "test.h"
// constants
using namespace std;
// function prototype
class DisjSets
{
public:
	explicit DisjSets(int numElements);
	int find(int x) const;
	int find(int x);
	void unionSets(int root1, int root2);
private:
	vector<int> s;
};
DisjSets::DisjSets(int numElements)
{
	for (int i = 0; i < s.size(); i++)
		s[i] = -1;
}

int DisjSets::find(int x) const
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

int DisjSets::find(int x)
{
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

void DisjSets::unionSets(int root1, int root2)
{
	s[root2] = root1;
}

int main()
{
	vector<int> test({ 10,9,8,7,6,5,4,3,2,1,0 });
	vector<double> test2({ 0.78, 0.17, 0.39, 0.26, 0.72, 0.34, 0.94, 0.21, 0.12, 0.23 });
	BucketSort<int> bucketsort(11);
	bucketsort.sort(test);
	cout << log2(320) << endl;
	/*BucketSortSimple(test);*/
	for (auto x : test)
		cout << x << " ";
	cout << endl;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}

