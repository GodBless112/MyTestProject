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
void BucketSortSimple(vector<int> &a)
{
	vector<int> bucket(a.size(), 0);
	for (int i = 0; i < a.size(); i++)
		bucket[a[i]]++;
	int index = 0;
	for (int i = 0; i < a.size(); i++)
		for (int j = 1; j <= bucket[i]; j++)
			a[index++] = i;
}
template<class T>
class BucketSort
{
private:
	struct ListNode
	{
		T element;
		ListNode *next;
		ListNode(const T &theElement = 0, ListNode *nextnode = nullptr)
			:element(theElement), next(nextnode) {}
	};
	int BucketSize;
	ListNode *Bucket;
public:
	BucketSort(int size = 10)
	{
		BucketSize = size;
		Bucket = new ListNode[size];
	}
	void sort(vector<T> &a)
	{
		int BucketIndex;
		ListNode *p, *q;
		int count = 0;
		for (int i = 0; i < a.size(); i++)
		{
			ListNode *insert = new ListNode(a[i], nullptr);
			BucketIndex = a[i] * 1;
			if (Bucket[BucketIndex].next == nullptr)
				Bucket[BucketIndex].next = insert;
			else
			{
				p = &Bucket[BucketIndex];
				q = p->next;
				while (q != nullptr&&q->element < a[i])
				{
					p = q;
					q = p->next;
				}
				insert->next = q;
				p->next = insert;
			}
		}
		for (int i = 0; i < BucketSize; i++)
		{
			p = Bucket[i].next;
			if (p == nullptr)
				continue;
			while (p != nullptr)
			{
				a[count++] = p->element;
				p = p->next;
			}
		}
	}
};
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

