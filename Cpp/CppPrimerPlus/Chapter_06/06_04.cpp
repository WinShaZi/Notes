#include <iostream>

using namespace std;

const int SIZE = 20;
const int NUM = 5;

void meau();

struct bop 
{
	char fullname[SIZE];
	char title[SIZE];
	char bopname[SIZE];
	int preference;
};

int main() 
{
	bop people[NUM] = { 
		{"Wimp Macho", "Teacher","Captain America", 0},
		{"Raki Rhides", "Junior Programmer", "Raytheon", 1},
		{"Celia Laiter", "Doctor","MIPS",2},
		{"Hoppy Hipman","Analyst Trainee","Black widow", 1},
		{"Pat Hand","Student", "LOOPY", 2}
	};
	char ch;

	meau();
	cout << "Enter your choice : ";
	while (cin >> ch && ch != 'q')
	{
		while (cin.get() != '\n');
		switch (ch)
		{
			case 'a':
				for (int i = 0; i < NUM; i++)
					cout << people[i].fullname << endl;
				break;
			case 'b':
				for (int i = 0; i < NUM; i++)
					cout << people[i].title << endl;
				break;
			case 'c':
				for (int i = 0; i < NUM; i++)
					cout << people[i].bopname << endl;
				break;
			case 'd':
				for (int i = 0; i < NUM; i++)
				{
					if (people[i].preference == 0)
						cout << people[i].fullname << endl;
					else if (people[i].preference == 1)
						cout << people[i].title << endl;
					else
						cout << people[i].bopname << endl;
				}
				break;
		}
		cout << "\nNext choice : ";
	}
	cout << "Bye!" << endl;

	system("pause");
	return 0;
}

void meau()
{
	cout << "Benevolent Order of Programmers Report           " << endl;
	cout << "a. display by name     b.display by title        " << endl;
	cout << "c. display by bopname  d. display by preference  " << endl;
	cout << "q. quit                                          " << endl;
}