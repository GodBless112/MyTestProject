// static.cpp -- using a static local variable
#include <iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<set>
#include "test.h"
// constants

// function prototype
using namespace std;
void Show(const string & s) { cout << s << " "; }
int main()
{
	set<string> Mat_friend;
	set<string> Pat_friend;
	ostream_iterator<string, char> out_iter(cout, " ");
	string temp;
	cout << "Enter Mat's friends (quit to quit):\n";
	getline(cin, temp);
	while (temp != "quit")
	{
		Mat_friend.insert(temp);
		getline(cin, temp);
	}
	cout << "Enter Pat's friends (quit to quit):\n";
	getline(cin, temp);
	while (temp != "quit")
	{
		Pat_friend.insert(temp);
		getline(cin, temp);
	}
	copy(Mat_friend.begin(), Mat_friend.end(), out_iter);
	cout << endl;
	copy(Pat_friend.begin(), Pat_friend.end(), out_iter);
	cout << endl;
	set<string> All_friend;
	set_union(Mat_friend.begin(), Mat_friend.end(), Pat_friend.begin(), Pat_friend.end(), insert_iterator<set<string> >(All_friend,All_friend.begin()));
	copy(All_friend.begin(), All_friend.end(), out_iter);
	cout << endl;
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
//int main()
//{
//	vector<string> Mat_friend;
//	vector<string> Pat_friend;
//	string temp;
//	cout << "Enter Mat's friends (quit to quit):\n";
//	getline(cin, temp);
//	while (temp != "quit")
//	{
//		Mat_friend.push_back(temp);
//		getline(cin, temp);
//	}
//	cout << "Enter Pat's friends (quit to quit):\n";
//	getline(cin, temp);
//	while (temp != "quit")
//	{
//		Pat_friend.push_back(temp);
//		getline(cin, temp);
//	}
//	sort(Mat_friend.begin(), Mat_friend.end());
//	for_each(Mat_friend.begin(), Mat_friend.end(), Show);
//	cout << endl;
//	sort(Pat_friend.begin(), Pat_friend.end());
//	for_each(Pat_friend.begin(), Pat_friend.end(), Show);
//	cout << endl;
//	vector<string> All_friend;
//	/*All_friend.insert(All_friend.begin(), Mat_friend.begin(), Mat_friend.end());
//	All_friend.insert(All_friend.begin(), Pat_friend.begin(), Pat_friend.end());*/
//	set_union(Mat_friend.begin(), Mat_friend.end(), Pat_friend.begin(), Pat_friend.end(), back_inserter(All_friend));
//	sort(All_friend.begin(), All_friend.end());
//	for_each(All_friend.begin(), All_friend.end(), Show);
//	cout << endl;
//	cout << "Done.\n";
//	// code to keep window open for MSVC++
//	cin.clear();
//	while (cin.get() != '\n')
//		continue;
//	cin.get();
//
//	return 0;
//}

