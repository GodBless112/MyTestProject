#pragma once
#ifndef TEST_H_
#define TEST_H_
class Tv
{
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {};
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void set_pattern(Remote & r);
private:
	int state;			//on or off
	int volume;			//assumed to be digitized
	int maxchannel;		//maximum number of channel
	int channel;
	int mode;			//broadcast or cable
	int input;			//TV or DVD
};
class Remote
{
private:
	int mode;			//control TV or DVD
	int pattern;			//normal or interact
public:
	friend class Tv;
	enum{Normal,Interact};
	Remote(int m = Tv::TV, int n = Normal) :mode(m), pattern(n) {};
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
	void set_pattern() { pattern = (pattern == Normal) ? Interact : Normal; }
	void ShowMode() const;
};
#endif // !TEST_H_

