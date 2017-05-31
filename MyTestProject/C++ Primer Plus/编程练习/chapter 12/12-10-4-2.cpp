#include <iostream>
#include "test.h"

Stack::Stack(int n)
{
	pitems = new Item[n];
	pitems[0] = '\0';
	top = 0;
	size = n;
}
Stack::Stack(const Stack & st)
{
	int i = 0;
	size = st.size;
	pitems = new Item[size];
	for (i = 0; i < st.top; i++)
		pitems[i] = st.pitems[i];
	top = st.top;
}
Stack::~Stack()
{
	delete[] pitems;
}
bool Stack::isempty() const
{
	return top == 0;
}
bool Stack::isfull() const
{
	return top == MAX;
}
bool Stack::push(const Item & item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}
bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack & Stack::operator=(const Stack & st)
{
	// TODO: 在此处插入 return 语句
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	pitems = new Item[size];
	for (int i = 0; i < st.top; i++)
		pitems[i] = st.pitems[i];
	top = st.top;
	return *this;
}
std::ostream & operator<<(std::ostream & os, const Stack & st)
{
	// TODO: 在此处插入 return 语句
	for (int i = 0; i < st.top; i++)
		os << st.pitems[i] << " ";
	os << std::endl;
	return os;
}