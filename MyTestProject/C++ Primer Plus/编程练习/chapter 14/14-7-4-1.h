#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
class Person
{
private:
	string firstname;
	string lastname;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Person() :firstname("null"), lastname("null") {}
	Person(const char * fn, const char * ln) :firstname(fn), lastname(ln) {}
	Person(const string & fn, const string & ln) :firstname(fn), lastname(ln) {}
	virtual ~Person() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};
class Gunslinger :virtual public Person
{
private:
	int numsk;
protected:
	void Data() const;
	void Get();
public:
	Gunslinger() :numsk(0), Person() {};
	Gunslinger(int n, const string & fn, const string & ln) :numsk(n), Person(fn, ln) {};
	Gunslinger(int n, const Person & p) :numsk(n), Person(p) {};
	void Show() const;
	void Set();
	double Draw() const;
};

class Card
{
private:
	enum { Spade, Heart, Club, Diamond };
	static char * pv[4];
	int suit;
	int number;
public:
	Card() :suit(0), number(1) {};
	Card(int s, int n) :suit(s), number(n) {};
	friend ostream & operator<<(ostream & os, const Card & c);
};

class PokerPlayer :virtual public Person
{
protected:
	void Data() const;
public:
	PokerPlayer() :Person() {};
	PokerPlayer(const string & fn, const string & ln) :Person(fn, ln) {};
	PokerPlayer(const Person & p) :Person(p) {};
	void Set() { Person::Set(); }
	void Show() const;
	Card Draw() const;
};

class BadDude :public Gunslinger, public PokerPlayer
{
protected:
	void Data() const;
	void Get();
public:
	BadDude() {};
	BadDude(int nk, const string & fn, const string & ln) :Person(fn, ln), Gunslinger(nk, fn, ln), PokerPlayer(fn, ln) {};
	BadDude(int nk, const Person & p) :Person(p), Gunslinger(nk, p), PokerPlayer(p) {};
	BadDude(const Gunslinger & g) :Person(g), Gunslinger(g), PokerPlayer(g) {};
	BadDude(int nk, const PokerPlayer & pp) :Person(pp), Gunslinger(nk, pp), PokerPlayer(pp) {};
	double Gdraw() const;
	Card Cdraw() const;
	void Set();
	void Show() const;
};
#endif // !TEST_H_

