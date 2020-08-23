#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int i, sum = 0;
    int sales[12];

    const string months[] = {"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};

    cout << "Sales" << endl;
    for(i = 0; i < 12; i++)
    {
        cout << left << setw(10) << months[i] << " : ";
        cin >> sales[i];
        sum += sales[i];
    }
    cout << "The total number of sales : " << sum << endl;

    system("pause");
    return 0;
}