// static.cpp -- using a static local variable
#include <iostream>
#include<string>
#include "test.h"
// constants
void set(Student & sa, int n);
// function prototype
const int puplis = 3;
const int quizzes = 5;
using namespace std;

int main(void)
{
	Student ada[puplis] = { Student(quizzes),Student(quizzes) ,Student(quizzes) };
	int i;
	for (i = 0; i < puplis; i++)
		set(ada[i], quizzes);
	cout << "\nStudent List:\n";
	for (i = 0; i < puplis; i++)
		cout << ada[i].Name() << endl;
	cout << "\nResults:";
	for (i = 0; i < puplis; i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

	return 0;
}

void set(Student & sa, int n)
{
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}