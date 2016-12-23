#include<iostream>
#include<cstring>
using namespace std;
struct stringy {
	char *str;
	int ct;
};
void set(stringy & y, char ch[]);
void show(const stringy & y, int n = 1);
void show(const char* str, int n = 1);
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);

	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done.");
	while (1);
	return 0;
}
void set(stringy & y,  char ch[])
{
	int n = strlen(ch);
	char *pt = new char[n + 1];
	pt = ch;
	y.str = pt;
	y.ct = n;

}
void show(const stringy & y, int n)
{
	for (int i = 0; i < n; i++)
		cout << y.str << endl;
}
void show(const char* str, int n)
{
	for (int i = 0; i < n; i++)
		cout << str << endl;
}