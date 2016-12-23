#include<iostream>
#include "test.h"
using namespace std;

void Person::Data() const
{
	cout << "Firstname: " << firstname << " "
		<< "Lastname: " << lastname << endl;
}
void Person::Get()
{
	cout << "Please enter the firstname:";
	getline(cin, firstname);
	cout << "Please enter the lastname:";
	getline(cin, lastname);
}
Person::~Person()
{
}
void Person::Set()
{
	Get();
}
void Person::Show() const
{
	Data();
}
void Gunslinger::Data() const
{
	cout << "The nick is: " << numsk << endl;
	cout << "The time of getting gun: " << Gunslinger::Draw() << endl;
}
void Gunslinger::Get()
{
	cout << "Pease enter the nick of the gun: ";
	cin >> numsk;
}
void Gunslinger::Show() const
{
	cout << "The Gunslinger's name is: " << endl;
	Person::Data();
	Data();
}
void Gunslinger::Set()
{
	cout << "Please enter the gunner's name: "<<endl;
	Person::Get();
	Get();
}

double Gunslinger::Draw() const
{
	return rand() / RAND_MAX * 3 + 1;
}

void PokerPlayer::Data() const
{
	cout << "The card is: " << Draw() << endl;
}

void PokerPlayer::Show() const
{
	cout << "The pokerplayer's name: "<<endl;
	Person::Data();
	Data();
}

Card PokerPlayer::Draw() const
{
	// TODO: 在此处插入 return 语句
	int suit, number;
	suit = rand() % 4;
	number = rand() % 52 + 1;
	return Card(suit, number);
}
char * Card::pv[] = { "Spade","Heart","Club","Diamond" };
ostream & operator<<(ostream & os, const Card & c)
{
	// TODO: 在此处插入 return 语句
	char *temp = Card::pv[c.suit];
	os << "The suit is: " << temp << endl;
	os << "The number is: " << c.number;
	return os;
}
void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout << "The next cards is: " << Cdraw() << endl;
	cout << "The time of BadDude getting gun: " << Gdraw() << endl;
}

void BadDude::Get()
{
	Gunslinger::Get();
}

double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

Card BadDude::Cdraw() const
{
	// TODO: 在此处插入 return 语句
	return PokerPlayer::Draw();
}

void BadDude::Set()
{
	cout << "Please enter the BadDude's name: " << endl;
	Person::Get();
	Get();
}

void BadDude::Show() const
{
	cout << "The BadDude's name is: " << endl;
	Person::Data();
	Data();
}
