#pragma once
#ifndef TEST_H_
#define TEST_H_
#include<iostream>
class Cd
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd(const Cd & d);
	Cd(){};
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};
class classic:public Cd
{
private:
	char * main_music;
public:
	classic() {};
	classic(char * m, char * s1, char * s2, int n, double x);
	classic(char * m, const Cd & d);
	classic(const classic & c);
	~classic();
	void Report() const;
	classic & operator=(const classic & c);
};
#endif // !TEST_H_

