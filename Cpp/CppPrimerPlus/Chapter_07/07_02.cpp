#include <iostream>
#include <array>

using namespace std;

int input(double ar[], int n);
double show(double ar[], int n);
void aver(double sum, int n);

int main()
{
	double ar[10] = { 0 };
	int n = input(ar, 10);

	aver(show(ar, n), n);

	system("pause");
	return 0;
}

int input(double ar[], int n)
{
	int i = 0;

	cout << "Input your grade : ";
	while (i < 10 && cin >> ar[i])
		i++;

	return i;
}

double show(double ar[], int n)
{
	double sum = 0;

	cout << "Here is your grades : " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << ' ';
		sum += ar[i];
	}

	return sum;
}

void aver(double sum, int n)
{
	cout << "\nAverage is " << sum / n << endl;
}