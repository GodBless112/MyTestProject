// static.cpp -- using a static local variable
#include <iostream>
#include "test.h"
// constants
//const int ArSize = 10;

// function prototype
void showfilm(Item &item);
using namespace std;
int main()
{
	using std::cout;
	using std::endl;
	List movies;
	Item temp;
	if (movies.isfull())
	{
		cout << "No more room in List!Bye!\n";
		exit(1);
	}
	cout << "Enter first movie title:\n";
	while (cin.getline(temp.title, TSIZE) && temp.title[0] != '\0')
	{
		cout << "Enter your rating<1-10>: ";
		cin >> temp.rating;
		while (cin.get() != '\n')
			continue;
		if (movies.additem(temp) == false)
		{
			cout << "List is already full!\n";
			break;
		}
		cout << "Enter next movie title(empty line to stop):\n";
	}
	if (movies.isempty())
		cout << "no data input!\n";
	else 
	{
		cout << "Here is the movei list:\n";
		movies.visit(showfilm);
	}
	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}
void showfilm(Item &item)
{
	std::cout << "Movies: " << item.title << " Rating"
		<< item.rating << std::endl;
}

