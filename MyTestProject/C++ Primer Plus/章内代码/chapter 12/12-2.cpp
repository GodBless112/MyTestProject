#include <cstring>
#include "test.h"
using std::cout;
int StringBad::num_strings = 0;
StringBad::StringBad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\"object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str,4, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\"object created\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\"object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete [] str;
}
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	// TODO: 在此处插入 return 语句
	os << st.str;
	return os;
}
