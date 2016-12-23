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
DisjSets::DisjSets(int numElements) :s(numElements)
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
	DisjSets test(10);
	cout << test.find(6) << endl;
	test.unionSets(1, 6);
	cout << test.find(6) << endl;
	
	cout << "Done.\n";
	// code to keep window open for MSVC++
	std::cin.clear();
	while (std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}

