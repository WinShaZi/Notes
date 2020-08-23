
//SALES.h
//*******************************************************************************************

namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}

//*******************************************************************************************

//SALES.cpp
//*******************************************************************************************

#include <iostream>
#include "SALES.h"

namespace SALES
{
	using std::cout;
	using std::endl;
	using std::cin;

	void setSales(Sales& s, const double ar[], int n)
	{    
		double min = ar[0], max = ar[0], sum = 0.0;

		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
			sum += ar[i];
			if (ar[i] < min)
				min = ar[i];
			if (ar[i] > max)
				max = ar[i];
		}
		s.average = sum / n;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales& s)
	{
		double ar[QUARTERS];

		cout << "Input 4 numbers : " << std::endl;
		for (int i = 0; i < QUARTERS; i++)
			cin >> ar[i];

		double min = ar[0], max = ar[0], sum = 0.0;

		for (int i = 0; i < QUARTERS; i++)
		{
			s.sales[i] = ar[i];
			sum += ar[i];
			if (ar[i] < min)
				min = ar[i];
			if (ar[i] > max)
				max = ar[i];
		}
		s.average = sum / QUARTERS;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s)
	{
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << " ";
		cout << endl;
		cout << "Average = " << s.average << endl;
		cout << "Maxute = " << s.max << endl;
		cout << "Minute = " << s.min << endl;
	}
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "SALES.h"

int main()
{
	SALES::Sales s1;
	SALES::Sales s2;
	int n;

	std::cout << "Input size of the array : ";
	std::cin >> n;
	double* pd = new double[n];
	std::cout << "Input " << n << " numbers : ";
	for (int i = 0; i < n; i++)
		std::cin >> pd[i];
	SALES::setSales(s1, pd, n);
	SALES::showSales(s1);

	std::cout << std::endl;
	SALES::setSales(s2);
	SALES::showSales(s2);
	delete[] pd;

	system("pause");
	return 0;
}

//*******************************************************************************************