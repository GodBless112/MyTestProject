// static.cpp -- using a static local variable
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<exception>
#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include "test.h"
// constants

// function prototype

using namespace std;
const char * mat = "mat.dat";
const char * pat = "pat.dat";
void Show(const string & s) { cout << s << " "; }
//int main()
//{
//	set<string> Mat_friend;
//	set<string> Pat_friend;
//	ostream_iterator<string, char> out_iter(cout, " ");
//	string temp;
//	ifstream fin1(mat);
//	ifstream fin2(pat);
//	ofstream fout("matpat.dat", ios_base::out | ios_base::trunc);
//	if (!fin1.is_open() || !fin2.is_open())
//	{
//		cerr << "Can't open file1 " << mat << " or file2 " << pat << endl;
//		exit(EXIT_FAILURE);
//	}
//	if (!fout.is_open())
//	{
//		cerr << "Can't open file matpat.dat to output.\n";
//		exit(EXIT_FAILURE);
//	}
//	while (!fin1.eof())
//	{
//		getline(fin1, temp);
//		Mat_friend.insert(temp);
//	}
//
//	while (!fin2.eof())
//	{
//		getline(fin2, temp);
//		Pat_friend.insert(temp);
//	}
//	copy(Mat_friend.begin(), Mat_friend.end(), out_iter);
//	cout << endl;
//	copy(Pat_friend.begin(), Pat_friend.end(), out_iter);
//	cout << endl;
//	set<string> All_friend;
//	set_union(Mat_friend.begin(), Mat_friend.end(), Pat_friend.begin(), Pat_friend.end(), insert_iterator<set<string> >(All_friend, All_friend.begin()));
//	copy(All_friend.begin(), All_friend.end(), out_iter);
//	cout << endl;
//	for (set<string>::iterator x = All_friend.begin(); x != All_friend.end(); x++)
//	{
//		fout << *x << endl;
//	}
//	fin1.close();
//	fin2.close();
//	fout.close();
//	cout << "Done.\n";
//	// code to keep window open for MSVC++
//	cin.clear();
//	while (cin.get() != '\n')
//		continue;
//	cin.get();
//
//	return 0;
//}
int main()
{
	vector<string> Mat_friend;
	vector<string> Pat_friend;
	ostream_iterator<string, char> out_iter(cout, " ");
	string temp;
	ifstream fin1(mat);
	ifstream fin2(pat);
	ofstream fout("matpat.dat", ios_base::out | ios_base::trunc);
	if (!fin1.is_open() || !fin2.is_open())
	{
		cerr << "Can't open file1 " << mat << " or file2 " << pat << endl;
		exit(EXIT_FAILURE);
	}
	if (!fout.is_open())
	{
		cerr << "Can't open file matpat.dat to output.\n";
		exit(EXIT_FAILURE);
	}
	while (!fin1.eof())
	{
		getline(fin1, temp);
		Mat_friend.push_back(temp);
	}

	while (!fin2.eof())
	{
		getline(fin2, temp);
		Pat_friend.push_back(temp);
	}
	sort(Mat_friend.begin(), Mat_friend.end());
	for_each(Mat_friend.begin(), Mat_friend.end(), Show);
	cout << endl;
	sort(Pat_friend.begin(), Pat_friend.end());
	for_each(Pat_friend.begin(), Pat_friend.end(), Show);
	cout << endl;
	vector<string> All_friend;
	/*All_friend.insert(All_friend.begin(), Mat_friend.begin(), Mat_friend.end());
	All_friend.insert(All_friend.begin(), Pat_friend.begin(), Pat_friend.end());*/
	set_union(Mat_friend.begin(), Mat_friend.end(), Pat_friend.begin(), Pat_friend.end(), back_inserter(All_friend));
	sort(All_friend.begin(), All_friend.end());
	for_each(All_friend.begin(), All_friend.end(), Show);
	cout << endl;
	for (auto x : All_friend)
	{
		fout << x << endl;
	}
	fin1.close();
	fin2.close();
	fout.close();
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


