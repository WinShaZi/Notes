#include <iostream>

using namespace std;

const int SIZE = 5;

template <typename T>
T max5(const T ar[]);

int main()
{
	int iar[5] = { 10, 20, 15, 16, 18 };
	double dar[5] = { 10.9, 20.1, 15.4, 16.7, 18.5 };

	cout << "Int max = " << max5(iar) << endl;
	cout << "Double max = " << max5(dar) << endl;

	system("pause");
	return 0;
}

template <typename T>
T max5(const T ar[])
{
	T temp = ar[0];

	for (int i = 1; i < SIZE; i++)
		if (temp < ar[i])
			temp = ar[i];

	return temp;
}