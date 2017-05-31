#pragma once
#ifndef TEST_H_
#define TEST_H_
template<class Item>
class QueneTP
{
private:
	enum { Q_SIZE = 10 };
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(const Item & i) :item(i), next(0) {};
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	QueneTP(const QueneTP & q) :qsize(0) {};
	QueneTP & operator=(const QueneTP & q) { return *this; }
public:
	QueneTP(int qs = Q_SIZE);
	~QueneTP();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int quenecount() const{ return items; }
	bool enquene(const Item & item);
	bool dequene(Item & item);
};
template<class Item>
inline QueneTP<Item>::QueneTP(int qs):qsize(qs)
{
	front = rear = 0;
	items = 0;
}
template<class Item>
QueneTP<Item>::~QueneTP()
{
	Node * temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<class Item>
inline bool QueneTP<Item>::enquene(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node(item);
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
template<class Item>
inline bool QueneTP<Item>::dequene(Item & item)
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
#endif // !TEST_H_

