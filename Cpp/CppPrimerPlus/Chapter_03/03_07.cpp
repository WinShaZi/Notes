#include <iostream>

using namespace std;

const double GALLON_LITER = 3.875;
const double MILE_METER = 1.609;

int main()
{
    double fuel;

    cout << "Input fuel ocnsumption per hundred : ";
    cin >> fuel;
    cout << (100 / MILE_METER) / (fuel / GALLON_LITER) << " mpg" << endl;   

    system("pause");
    return 0;
}