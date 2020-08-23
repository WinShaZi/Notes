
//tv.h
//*******************************************************************************************

#ifndef TV_H
#define TV_H

class Remote;
class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void set_remote_mode(Remote& r);
};

class Remote
{
private:
	int mode;
public:
	friend class Tv;
	enum { Normal, Interact };
	Remote(int m = Normal) : mode(m) {}

	void showmode() const;
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
};
#endif

//*******************************************************************************************

//tv.cpp
//*******************************************************************************************

#include <iostream>
#include "tv.h"

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
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
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "Antenna" : "Cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::set_remote_mode(Remote& r)
{
	if (state == On)
		r.mode = (r.mode == Remote::Normal) ? Remote::Interact : Remote::Normal;
}

void Remote::showmode() const
{
	using std::cout;
	using std::endl;
	cout << "Remote mode is : " << (mode == Normal ? "Normal" : "Interact") << endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "tv.h"

int main()
{
	using std::cout;
	using std::endl;

	Tv s42;
	Remote grey;
	cout << "Initial setting for 42\" TV : " << endl;
	s42.settings();

	cout << endl;
	grey.showmode();
	s42.set_remote_mode(grey);
	grey.showmode();
	cout << endl;

	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV : " << endl;
	s42.settings();

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote : " << endl;
	s42.settings();
	cout << endl;

	grey.showmode();
	s42.set_remote_mode(grey);
	grey.showmode();

	system("pause");
	return 0;
}

//*******************************************************************************************