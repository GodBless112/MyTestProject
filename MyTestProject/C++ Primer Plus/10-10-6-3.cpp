// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
using namespace std;
int main()
{
	using std::cout;
	using std::endl;
	Move move1(4,5);
	Move move2(2,1);
	Move move3;
	cout<<"The number in move1 is:\n";
	move1.showMove();
	cout<<"The number in move2 is:\n";
	move2.showMove();
	move3=move2.add(move1);
	cout<<"The number in move3 is :\n";
	move3.showMove();
	cout<<"move1+move2,mow move'2s number is :\n";
	move2.showMove();
	cout<< "After move1 + move2,now move1's number is :\n";
	move1.showMove();
	move1.reset();
	cout<< "After reset move1,now move1's number is:\n";
	move1.showMove();
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

