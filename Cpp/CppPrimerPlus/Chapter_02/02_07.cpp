#include <iostream>

using namespace std;

void show(int h, int m);

int main()
{
	int hour, minute;

	cout << "Enter the number of hours : ";
	cin >> hour;
	cout << "Enter the number of minutes : ";
	cin >> minute;
	show(hour, minute);

	system("pause");
	return 0;
}

void show(int h, int m)
{
	cout << "Time : " << h << ':' << m << endl;
}