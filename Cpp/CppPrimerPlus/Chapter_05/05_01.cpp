#include <iostream>

using namespace std;

int add(int min, int max);

int main()
{
	int min, max;

	cout << "Enter minimum : ";
	cin >> min;
	cout << "Enter maximum : ";
	cin >> max;

	cout << "Their sum is : " << add(min, max) << endl;

	system("pause");
	return 0;
}

int add(int min, int max)
{
	int sum = 0;

	for (; min <= max; min++)
		sum += min;

	return sum;
}