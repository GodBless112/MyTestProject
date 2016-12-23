#include<iostream>
#include "test.h"
using namespace std;

bool Tv::volup()
{
	if (volume >= MaxVal)
		return false;
	else
	{
		volume++;
		return true;
	}
}

bool Tv::voldown()
{
	if (volume <= MinVal)
		return false;
	else
	{
		volume--;
		return true;
	}
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::set_pattern(Remote & r)
{
	if (ison())
		r.set_pattern();
}

void Remote::ShowMode() const
{
	cout << "Remote pattern = " << ((pattern == Normal) ? "Normal" : "Interact") << endl;
}