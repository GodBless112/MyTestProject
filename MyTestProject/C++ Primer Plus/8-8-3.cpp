#include<iostream>
#include<string>
using namespace std;
void transfer(string & str);
int main()
{
	string str;
	cout << "Enter a string (1 to quit):";
	getline(cin, str);
	while (str != "q" && str != "Q")
	{
		transfer(str);
		cout << str << endl;
		cout << "Enter a string (1 to quit):";
		getline(cin, str);
	}
	cout << "end." << endl;
	while (1);
	return 0;
}

void transfer(string & str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}
