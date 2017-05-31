#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
template<class T>
class QueueTP
{
private:
	struct Node
	{
		T item;
		struct Node * next;
	};
	struct Node * front;
	struct Node * rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP & q) :qsize(0) {};
	QueueTP & operator=(const QueueTP & q) { return *this; }
public:
	QueueTP(int qs = 10);
	~QueueTP();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const T & item);
	bool dequeue(T & item);
};
class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() :fullname("no one"), id(0L) {}
	Worker(const std::string & s, long n) :fullname(s), id(n) {}
	~Worker();
	void Set();
	void Show() const;
};

#endif // !TEST_H_

template<class T>
inline QueueTP<T>::QueueTP(int qs):qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

template<class T>
inline QueueTP<T>::~QueueTP()
{
	Node * temp;
	while (front != NULL)//队列不为空
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<class T>
inline bool QueueTP<T>::isempty() const
{
	return items == 0;
}

template<class T>
inline bool QueueTP<T>::isfull() const
{
	return items==qsize;
}

template<class T>
inline int QueueTP<T>::queuecount() const
{
	return items;
}

template<class T>
inline bool QueueTP<T>::enqueue(const T & item)
{
	if (isfull())
		return false;
	Node * add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)//队列为空
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<class T>
inline bool QueueTP<T>::dequeue(T & item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}
