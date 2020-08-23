#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Time
{
private:
	unsigned years;
	string months;
	unsigned days;
public:
	Time() : years(2000), months("jan"), days(1) {}
	Time(const string &stm);
	void print();
};

Time::Time(const string &stm)
{
	const vector<string> mon{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Setp", "Oct", "Nov", "Dec" };
	int mode = 0;
	string t;

	if (stm.find(',') != string::npos)
		mode = 1;
	else if (stm.find('/') != string::npos)
		mode = 2;
	else
		mode = 3;

	switch (mode)
	{
	case 1:
	{
		int i = 0;
		int j;

		while (i < 12)
		{
			if (stm.find(mon[i]) != string::npos)
			{
				months = mon[i];
				break;
			}
			i++;
		}
		i = stm.find_first_of(' ');
		j = stm.find_first_of(',');
		t = stm.substr(i + 1, j - i - 1);
		days = stoul(t);

		i = stm.find_last_of(' ');
		t = stm.substr(i + 1, stm.size() - j - 1);
		years = stoul(t);
	}
	break;
	case 2:
	{
		int i = stm.find_first_of('/');
		int j = stm.find_last_of('/');

		t = stm.substr(0, i);
		days = stoul(t);


		t = stm.substr(i + 1, j - i - 1);
		months = mon[stoul(t) - 1];

		t = stm.substr(j + 1, stm.size() - j - 1);
		years = stoul(t);
	}
	break;
	case 3:
	{
		int i = stm.find_first_of(' ');
		int j = stm.find_last_of(' ');
		int n = 0;

		while (n < 12)
		{
			if (stm.find(mon[n]) != string::npos)
			{
				months = mon[n];
				break;
			}
			n++;
		}

		t = stm.substr(i + 1, j - i - 1);
		days = stoul(t);

		t = stm.substr(j + 1, stm.size() - j - 1);
		years = stoul(t);
	}
	break;
	default:
		Time();
	}
}

void Time::print()
{
	cout << years << " : " << months << " : " << days << endl;
}


int main()
{
	Time T1("January 1, 1900");
	Time T2("1/1/1990");
	Time T3("Jan 1 1900");

	T1.print();
	T2.print();
	T3.print();

	system("pause");
	return 0;
}