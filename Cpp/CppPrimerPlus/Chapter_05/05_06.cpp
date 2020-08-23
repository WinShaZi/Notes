#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int sum = 0;
	int sales[3][12];
	const string years[] = { "The first year", "The second year", "The third year" };
	const string months[] = { "January", "February", "March", "April", "May",
	"June", "July", "August", "September", "October", "November", "December" };

	cout << "Sales" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << right << setw(20) << years[i] << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << left << setw(10) << months[j] << " : ";
			cin >> sales[i][j];
			sum += sales[i][j];
		}
	}
	cout << "The total number of sales : " << sum << endl;

	system("pause");
	return 0;
}