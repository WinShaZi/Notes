#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char name[20];
	double quality;
	int calorimeter;
};

void fill(CandyBar& candy, char ch[], double weight, int heat);
void show(const CandyBar& candy);

int main()
{
	CandyBar candybar;
	char ch[] = "Millennum Munch";
	double weight = 2.85;
	int heat = 350;

	fill(candybar, ch, weight, heat);
	show(candybar);

	system("pause");
	return 0;
}

void fill(CandyBar& candy, char ch[], double weight, int heat)
{
	strcpy(candy.name, ch);
	candy.quality = weight;
	candy.calorimeter = heat;
}

void show(const CandyBar& candy)
{
	cout << candy.name << endl;
	cout << candy.quality << endl;
	cout << candy.calorimeter << endl;
}