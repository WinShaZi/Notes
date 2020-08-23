#include <iostream>

using namespace std;

int main()
{
    double x = 100, y = 100;
    int year = 0;

    while (x >= y)
    {
        x += 10;
        y *= 1.05;
        year++;
    }
    cout << year << endl;

    system("pause");
    return 0;
}