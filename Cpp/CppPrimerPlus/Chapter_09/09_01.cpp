
//golf.h
//*******************************************************************************************

const int LEN = 40;

struct golf
{
	char fullname[LEN];
	int handicap;
};

void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);

//*******************************************************************************************

//golf.cpp
//*******************************************************************************************

void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	if (g.fullname[0] == '\0')
		return 0;

	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << "Name : ";
	std::cout << g.fullname << std::endl;
	std::cout << "Handicap : ";
	std::cout << g.handicap << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "golf.h"

int main()
{
	using namespace std;

	golf* andy = new golf[LEN];
	int grade;
	int n = 1;

	setgolf(andy[0], "LIU", 21);
	cout << "Input " << n + 1 << "-th name : ";
	while (n < LEN && cin.getline(andy[n].fullname, LEN))
	{
		if (!setgolf(andy[n]))
			break;
		cout << "Input " << n + 1 << "-th grade : ";
		if (!(cin >> grade))
			break;
		handicap(andy[n], grade);
		while (cin.get() != '\n');
		n++;
		cout << "Input " << n + 1 << "-th name : ";
	}
	for (int i = 0; i < n; i++)
		showgolf(andy[i]);
	if (n > 0)
		cout << "Done!" << endl;
	else
		cout << "None!" << endl;

	system("pause");
	return 0;
}

//*******************************************************************************************