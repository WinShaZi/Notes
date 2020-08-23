#include <iostream>
#include <cmath>

using namespace std;

const double FOOT_M = 0.3048;
const double INCH_M = 0.0254;
const double LB_KG = 2.2;

int main()
{
    double height_foot;
    double height_inch;
    double weight;
    double bmi;

    cout << "Input your height (__FT __IN): ";
    cin >> height_foot >> height_inch;
    cout << "Input your weight (LB): ";
    cin >> weight;
    bmi = (weight / LB_KG) / pow((height_foot * FOOT_M) + (height_inch * INCH_M), 2);
    cout << "Your BMI is : " << bmi << endl;

    system("pause");
    return 0;
}