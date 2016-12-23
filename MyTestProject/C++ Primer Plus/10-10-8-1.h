#pragma once
#ifndef TEST_H_
#define TEST_H_
const int TSIZE = 50;
struct film
{
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
class List
{
private:
	static const int ListLen = 10;
	Item items[ListLen];
	int count;
public:
	List();
	bool isempty();
	bool isfull();
	int itemcount();
	bool additem(Item & item);
	void visit(void (*pf)(Item &));
};

#endif // !TEST_H_

