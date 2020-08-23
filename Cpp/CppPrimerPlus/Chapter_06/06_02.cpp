#include <iostream>
#include <cctype>

using namespace std;

const int SIZE = 10;

int main()
{
	double donation[SIZE];
	int i = 0, sum = 0, num = 0;
	double average;

	while (i < SIZE && cin >> donation[i])
		sum += donation[i++];
	average = double(sum / i);
	cout << "Average : " << average << endl;
	while (--i >= 0)
		if (donation[i] > average)
			num++;
	cout << "Number : " << num << endl;

	system("pause");
	return 0;
}