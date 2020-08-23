#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct Sales_data 
{
	Sales_data();
	string bookNo;
	unsigned units_sold ;
	double revenue ;
};

Sales_data::Sales_data()
{
	units_sold = 0;
	revenue = 0.0;
}
 
int main()
{
	Sales_data total;

	if (cin >> total.bookNo >> total.units_sold >> total.revenue) 
	{
		Sales_data trans;

		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) 
		{
			if (total.bookNo == trans.bookNo) 
			{
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else 
			{
				cout << total.bookNo << " " << total.units_sold << " "
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else 
	{
		cerr << "No data?!" << endl;
		
		return -1;
	}

	system("pause");
	return 0;
}