#include<cstring>
#include "test.h"
using namespace std;

Cd::Cd(char * s1, char * s2, int n, double x)
{
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label:      " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime:   " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	// TODO: 在此处插入 return 语句
	if (this == &d)
		return *this;
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

classic::classic(char * m, char * s1, char * s2, int n, double x) :Cd(s1, s2, n, x)
{
	strcpy_s(main_music, strlen(m) + 1, m);
}

classic::classic(char * m, const Cd & d) : Cd(d)
{
	strcpy_s(main_music, strlen(m) + 1, m);
}

classic::~classic()
{
}

void classic::Report() const
{
	Cd::Report();
	cout << "Main music: " << main_music << endl;
}

classic & classic::operator=(const classic & c)
{
	// TODO: 在此处插入 return 语句
	if (this == &c)
		return *this;
	Cd::operator=(c);
	strcpy_s(main_music, strlen(c.main_music) + 1, c.main_music);
}
