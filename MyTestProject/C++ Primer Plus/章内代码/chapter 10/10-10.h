#pragma once
#ifndef TEST_H_
#define TEST_H_
typedef unsigned long Item;
class Stack
{
private:
	enum {MAX=10};
	Item items[10];
	int top;
public:
	Stack();
	//~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
};

#endif // !TEST_H_
