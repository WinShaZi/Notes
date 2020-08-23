#include <iostream>

using namespace std;

int fact()
{
	static int count = 0;

	count++;

	return count;
}

int main()
{
	int i = 100;

	for (int i = 0; i < 10; i++)
		cout << fact() << ' ';


	system("pause");
	return 0;
}