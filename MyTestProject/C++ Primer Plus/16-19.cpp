// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<cctype>
#include "test.h"
// constants
// function prototype
using namespace std;
char toLower(char ch) { return tolower(ch); }
string & ToLower(string & st);
void display(const string & s);
int main(void)
{
	vector<string> words;
	cout << "Enter words (enter quit to quit):\n";
	string input;
	while (cin >> input&&input != "quit")
		words.push_back(input);
	cout << "You entered the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;
	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	map<string, int> wordmap;
	for(auto x:wordset)
	{
		wordmap[x] = count(words.begin(), words.end(), x);
	}
	cout << "\nWord frequency:\n";
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); ++si)
		cout << *si << ": " << wordmap[*si] << endl;
	for (auto x : wordset)
		cout << x <<": "<< wordmap[x] << endl;

	
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

string & ToLower(string & st)
{
	// TODO: 在此处插入 return 语句
	transform(st.begin(), st.end(),st.begin(), toLower);
	return st;
}

void display(const string & s)
{
	cout << s << ' ';
}
