#include <cstring>
#include "test.h"
using std::cout;
int String::num_strings = 0;
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0]='\0';
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete [] str;
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
