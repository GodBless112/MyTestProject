#include <cstring>
#include<cstdlib>
#include<ctime>
#include "test.h"
using std::cout;
Quene::Quene(int qs):qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
Quene::~Quene()
{
	Node * temp;
	while (front!= NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Quene::isempty() const
{
	return items==0;
}

bool Quene::isfull() const
{
	return items==qsize;
}

int Quene::quenecount() const
{
	return items;
}

bool Quene::enquene(const Item & item)
{
	if (isfull())
		return false;
	Node *add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Quene::dequene(Item & item)
{
	if (isempty())
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
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}