#include <iostream>

using namespace std;

void show_1();

void show_2();

int main()
{
	show_1();
	show_1();
	show_2();
	show_2();

	system("pause");
	return 0;
}

void show_1()
{
	cout << "Three blind mice" << endl;
}

void show_2()
{
	cout << "See how they run" << endl;
}
