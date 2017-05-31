// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
using namespace std;
// constants

template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) :item(i) { }
	~ManyFriend() { }
	template<typename C, typename D> friend void show2(C & c, D & d);
};


template<typename C, typename D> 
void show2(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;
}

// function prototype

int main(void)
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

