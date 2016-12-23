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
void ShowStr(const string & s) { cout << s << endl; }
class Store
{
private:
	ostream &os;
public:
	Store(ostream & ros) :os(ros) {};
	void operator() (const string & s);
};
void GetStrs(ifstream & ifs, vector<string> & vs);
int main()
{
	vector<string> vostr;
	string temp;
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	ofstream fout("strings.dat", ios::out | ios::binary|ios::app);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	vector<string> vistr;
	ifstream fin("strings.dat", ios::in | ios::binary);
	if (!fin.is_open())
	{
		cerr << "Can't open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	cout << "Done.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void Store::operator()(const string & s)
{
	size_t len = s.size();
	os.write((char *)&len, sizeof(size_t));
	os.write(s.data(), len);
}

void GetStrs(ifstream & ifs, vector<string> &vs)
{
	size_t len;
	char * s;
	string temp;
	while (ifs.read((char *)&len, sizeof(size_t)))
	{
		/*temp.erase();
		for (int i = 0; i < len; i++)
		{
			char ch;
			ifs.read(&ch, 1);
			temp += ch;
		}
		vs.push_back(temp);
		*/
		/*s = new char[len + 1];
		ifs.read(s, len);
		s[len] = '\0';
		temp = s;
		vs.push_back(temp);
		delete[] s;*/
		temp = "";
		for (int i = 0; i < len; i++)
		{
			char ch;
			ifs.read(&ch, 1);
			temp.insert(temp.end(), ch);
		}
		vs.push_back(temp);
	}
}
