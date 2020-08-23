#include <iostream>

using namespace std;

int Fill_array(double ar[], int n);
void Show_array(double ar[], int n);
void Reverse_array(double ar[], int n);
void reverse(double ar[], int n, int num);

int main()
{
	double ar[10] = { 0 };
	int i;

	i = Fill_array(ar, 10);
	Show_array(ar, i);
	Reverse_array(ar, i);

	system("pause");
	return 0;
}

int Fill_array(double ar[], int n)
{
	int i = 0;

	cout << "Input 10 number : ";
	while (i < n && cin >> ar[i])
		i++;

	return i;
}

void Show_array(double ar[], int n)
{
	for (int i = 0; i < n; i++)
		cout << ar[i] << ' ';
	cout << endl;
}

void Reverse_array(double ar[], int n)
{
	reverse(ar, n, 0);
	Show_array(ar, n);
	reverse(ar, n, 0);
	reverse(ar, n, 1);
	Show_array(ar, n);
}

void reverse(double ar[], int n, int num)
{
	double temp;

	for (int i = num; i < n / 2; i++)
	{
		temp = ar[n - 1 - i];
		ar[n - 1 - i] = ar[i];
		ar[i] = temp;
	}
}