#include <iostream>

using namespace std;

const int SEASON = 4;

const char* season[10] = {
	"Spring",
	"Summer",
	"Fall",
	"Winter"
};

struct season_b
{
	double expenses_b;
};

void fill_a(double expenses_a[]);
void show_a(double expenses_a[]);
void fill_b(season_b* ps);
void show_b(season_b* ps);

int main()
{
	double expenses_a[SEASON] = { 0 };
	season_b* ps = new season_b[4];

	fill_a(expenses_a);
	show_a(expenses_a);
	cout << endl;
	fill_b(ps);
	show_b(ps);

	delete[] ps;

	system("pause");
	return 0;
}

void fill_a(double expenses_a[])
{
	for (int i = 0; i < SEASON; i++)
	{
		cout << "Enter " << season[i] << " expenses : ";
		cin >> expenses_a[i];
	}
}

void show_a(double expenses_a[])
{
	double total = 0;

	cout << "\nEXPENSES" << endl;
	for (int i = 0; i < SEASON; i++)
	{
		cout << season[i] << " : $" << expenses_a[i] << endl;
		total += expenses_a[i];
	}
	cout << "Total expenses : $" << total << endl;
}

void fill_b(season_b* ps)
{
	for (int i = 0; i < SEASON; i++)
	{
		cout << "Enter " << season[i] << " expenses : ";
		cin >> ps[i].expenses_b;
	}
}

void show_b(season_b* ps)
{
	double total = 0;

	cout << "\nEXPENSES" << endl;
	for (int i = 0; i < SEASON; i++)
	{
		cout << season[i] << " : $" << ps[i].expenses_b << endl;
		total += ps[i].expenses_b;
	}
	cout << "Total expenses : $" << total << endl;
}