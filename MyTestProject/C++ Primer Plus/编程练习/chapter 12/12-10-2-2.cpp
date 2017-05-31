#include <cstring>
#include "test.h"
using std::cout;
int String::num_strings = 0;
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[] str;
}
String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
}
String & String::operator=(const String & st)
{
	// TODO: 在此处插入 return 语句
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}
String & String::operator=(const char * s)
{
	// TODO: 在此处插入 return 语句
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}
String & String::operator+(const char * s)
{
	// TODO: 在此处插入 return 语句
	int lens = strlen(str) + strlen(s) + 1;
	char * ps = new char[lens + 1];
	strcpy_s(ps, lens + 1, str);
	strcat_s(ps, lens + 1, s);
	return String(ps);
}
void String::Stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}
void String::Stringup()
{
	for (int i = 0; i < len; i++)
	{
		if (islower(str[i]))
			str[i] = toupper(str[i]);
	}
}
int String::has(const char s) const
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == s)
			count++;
	}
	return count;
}
char & String::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	return str[i];
}
const char & String::operator[](int i) const
{
	// TODO: 在此处插入 return 语句
	return str[i];
}
int String::HowMany()
{
	return num_strings;
}
String operator+(const char * s, const String st)
{
	int lens = strlen(st.str) + strlen(s) + 1;
	char * ps = new char[lens + 1];
	strcpy_s(ps, lens + 1, s);
	strcat_s(ps, lens + 1, st.str);
	return String(ps);
}
std::ostream & operator<<(std::ostream & os, const String & st)
{
	// TODO: 在此处插入 return 语句
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	// TODO: 在此处插入 return 语句
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}

bool operator<(const String & st1, const String & st2)
{
	return strcmp(st1.str, st2.str) < 0;
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return strcmp(st1.str, st2.str) == 0;
}

String operator+(const String & st1, const String & st2)
{
	int lens = strlen(st1.str) + strlen(st2.str) + 1;
	char * ps = new char[lens + 1];
	strcpy_s(ps, lens + 1, st1.str);
	strcat_s(ps, lens + 1, st2.str);
	return String(ps);
}
