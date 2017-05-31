// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
using namespace std;
// constants
template<typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T & i) :item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void reports(HasFriend<T> &);
};


template<typename T>
int HasFriend<T>::ct = 0;
void counts()
{
	cout << "int count: " << HasFriend<int>::ct << "; ";
	cout << "double count: " << HasFriend<double>::ct << endl;
}
void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}
void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}


// function prototype

int main(void)
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared: ";
	counts();
	HasFriend<double> hfdb(10.5);
	cout << "After hfdb declared: ";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	cout << "Bye.\n";
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}


