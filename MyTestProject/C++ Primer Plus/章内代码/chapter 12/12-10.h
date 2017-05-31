#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer(){ arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
typedef Customer Item;

class Quene
{
private:
	struct Node { Item item; struct Node * next; };
	enum { Q_SIZE = 10 };
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	Quene(const Quene & q): qsize(0){}
	Quene & operator=(const Quene & q) { return *this; }
public:
	Quene(int qs = Q_SIZE);
	~Quene();
	bool isempty() const;
	bool isfull() const;
	int quenecount() const;
	bool enquene(const Item & item);
	bool dequene(Item & item);
};
#endif // !TEST_H_

