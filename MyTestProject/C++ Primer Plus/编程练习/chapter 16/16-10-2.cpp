// static.cpp -- using a static local variable
#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<initializer_list>
#include<algorithm>
#include<cstdlib>
#include "test.h"
// constants
// function prototype
using namespace std;
bool isReverse(const string & s1, const string & s2);
void ToLower(string& str);
int main(void)
{
	string word;
	cout << "Enter a word (quit to quit): ";
	getline(cin, word);
	while (word != "quit")
	{
		//string rword(word.rbegin(), word.rend());
		/*string rword;
		copy(word.rbegin(), word.rend(), back_inserter(rword));*/   
		//注意copy()无法改变容器大小，所以不能简单使用迭代器begin()，需要使用back_inserter或者insert_iterator
		ToLower(word);
		string rword;
		copy(word.rbegin(), word.rend(), insert_iterator<string>(rword,rword.begin()));
		cout << "The word is: " << word << endl;
		if (isReverse(rword, word))
			cout << "The word: " << word << " is reverse!\n";
		else
			cout << "The word: " << word << " is not reverse!\n";
		cout << "Enter next word (quit to quit): ";
		getline(cin, word);
	}
	cout << "Bye.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

bool isReverse(const string & s1, const string & s2)
{
	int a = s1.compare(s2);
	if (a)
		return false;
	else
		return true;
}
void ToLower(string& str)
{
	unsigned int i = 0;
	while (i < str.size())
	{
		if (isalpha(str[i]))
		{
			str[i] = tolower(str[i]);
			i++;
		}
		else
		{
			//str.erase(str.begin()+i);
			//str.erase(i,1);
			str.replace(i, str.size(), str, i + 1, str.size());
		}
	}
}