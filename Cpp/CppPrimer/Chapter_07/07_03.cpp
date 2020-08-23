#include <iostream>
#include<string>

using namespace std;

struct Sales_data 
{
	Sales_data();
	Sales_data combine(const Sales_data * rhs);
	string bookNo;
	unsigned units_sold ;
	double revenue ;
};

Sales_data::Sales_data()
{
	units_sold = 0;
	revenue = 0.0;
}

Sales_data Sales_data::combine(const Sales_data * rhs)
{
    units_sold += rhs->units_sold;
    revenue += rhs->revenue;

    return *this;
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
				total.combine(&trans);
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