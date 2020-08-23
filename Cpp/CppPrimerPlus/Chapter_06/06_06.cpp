#include <iostream>
#include <string>

using namespace std;

struct message
{
	string name;
	double money;
};

void show_grand(message* ps, int number);

void show_other(message* ps, int number);

int main() 
{
	int number;

	cout << "Please enter the number of people : ";
	cin >> number;
	cin.get();

	message* ps = new message[number];
	for (int i = 0; i < number; i++)
	{
		cout << "Please enter the " << i + 1 << "-th name : ";
		getline(cin, ps[i].name);
		cout << "Please enter the " << i + 1 << "-th money :";
		cin >> ps[i].money;
		cin.get();
	}

	cout << "Patrons" << endl;
	show_grand(ps, number);
	show_other(ps, number);

	system("pause");
	return 0;
}

void show_grand(message* ps, int number)
{
	cout << "Grand Patrons : " << endl;
	int grand = 0;
	for (int i = 0; i < number; i++)
	{

		if (ps[i].money > 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			grand++;
		}
	}
	if (grand == 0)
		cout << "none" << endl;
}

void show_other(message* ps, int number)
{
	int other = 0;

	cout << "Other Patrons : " << endl;
	for (int i = 0; i < number; i++)
	{

		if (ps[i].money <= 10000)
		{
			cout << ps[i].name << " " << ps[i].money << endl;
			other++;
		}
	}
	if (other == 0)
		cout << "none" << endl;
}