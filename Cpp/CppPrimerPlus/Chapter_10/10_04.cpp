
//sale.h
//*******************************************************************************************

#ifndef SALE_H_
#define SALE_H_

namespace SALES
{
	const int QUARTERS = 4;

	class Sales
	{
	private:
		double _sales[QUARTERS];
		double _average;
		double _max;
		double _min;
	public:
		Sales(const double sales[], int n);
		void setSales();
		void showSales() const;
	};
}

#endif

//*******************************************************************************************

//sale.cpp
//*******************************************************************************************

#include <iostream>
#include "sale.h"

SALES::Sales::Sales(const double ar[], int n)
{
	using std::cout;
	using std::endl;
	using std::cin;

	for (int i = 0; i < QUARTERS; i++)
		_sales[i] = 0.0;

	double min = ar[0], max = ar[0], sum = 0.0;

	for (int i = 0; i < n; i++)
	{
		_sales[i] = ar[i];
		sum += ar[i];
		if (ar[i] < min)
			min = ar[i];
		if (_sales[i] > max)
			max = ar[i];
	}
	_average = sum / n;
	_max = max;
	_min = min;
}

void SALES::Sales::setSales()
{
	using std::cout;
	using std::endl;
	using std::cin;

	double ar[QUARTERS];

	cout << "Input 4 numbers : ";
	for (int i = 0; i < QUARTERS; i++)
		cin >> ar[i];

	double min = ar[0], max = ar[0], sum = 0.0;

	for (int i = 0; i < QUARTERS; i++)
	{
		_sales[i] = ar[i];
		sum += _sales[i];
		if (_sales[i] < min)
			min = _sales[i];
		if (_sales[i] > max)
			max = _sales[i];
	}
	_average = sum / QUARTERS;
	_max = max;
	_min = min;
}

void SALES::Sales::showSales() const
{
	for (int i = 0; i < QUARTERS; i++)
		std::cout << _sales[i] << ' ';
	std::cout << std::endl;
	std::cout << "Average : " << _average << std::endl;
	std::cout << "Maxute : " << _max << std::endl;
	std::cout << "Minute : " << _min << std::endl;
}

//*******************************************************************************************

//main.cpp
//*******************************************************************************************

#include <iostream>
#include "sale.h"

int main()
{
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int n;

		cout << "Input size of array : ";
		cin >> n;

		double* ar = new double[n];

		cout << "Input " << n << " number : ";
		for (int i = 0; i < n; i++)
			cin >> ar[i];
		SALES::Sales sa(ar, n);
		sa.showSales();

		sa.setSales();
		sa.showSales();

		delete[] ar;
	}
	
	system("pause");
	return 0;
}

//*******************************************************************************************