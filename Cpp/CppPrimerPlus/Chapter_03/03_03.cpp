#include <iostream>

using namespace std;

const int TRANSFORM = 60;

int main()
{
    double degree, minute, second;
    double latitude;

    cout << "Enter a latitude in degrees, minute, and seconds : " << endl;
    cout << "First, enter the degrees : ";
    cin >> degree;
    cout << "Next, enter the minutes : ";
    cin >> minute;
    cout << "Finally, enter the seconds : ";
    cin >> second;
    latitude = degree + minute / TRANSFORM + second / (TRANSFORM * TRANSFORM);
    cout << degree << " degrees, " << minute << " minutes, ";
    cout << second << " seconds = " << latitude << " degrees" << endl;

    system("pause");
    return 0;
}