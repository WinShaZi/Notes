#include <iostream>

using namespace std;

const float FOOT_INCH = 12;

int main()
{
    float height;
    int foot;
    float inch;

    cout << "Input your height (inches): ";
    cin >> height;
    foot = height / FOOT_INCH;
    inch = height - foot * FOOT_INCH ;
    cout << "Your height is " << foot << " foots ";
    cout << inch << " inches" << endl;

    system("pause");
    return 0;
}