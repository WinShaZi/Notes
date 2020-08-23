#include <iostream>

using namespace std;

const float RATE_0 = 0;
const float RATE_1 = 0.1;
const float RATE_2 = 0.15;
const float RATE_3 = 0.2;

int main() 
{
    float income, tax;

	cout << "Please enter your income : ";
	while (cin >> income && income > 0)
	{
		while (cin.get() != '\n');
		if (income < 5000)
			tax = 0;
		else if (income < 15000)
			tax = 5000 * RATE_0 + (income - 5000) * RATE_1;
		else if (income < 35000)
			tax = 5000 * RATE_0 + 10000 * RATE_1 + (income - 15000) * RATE_2;
		else
			tax = 5000 * RATE_0 + 10000 * RATE_1 + 20000 * RATE_2 + (income - 35000) * RATE_3;
		cout << "The tax that you should pay is : " << tax << endl;
		cout << "Please enter your income : ";
	}

	system("pause");
	return 0;
}