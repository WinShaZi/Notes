#include<iostream>

using namespace std;

int main() 
{
    const double GALLON_LITER = 3.875;
    const double MILE_METER = 1.609;
    double mile, gallon;
    int mode;
 
    cout << "Input distance (mile) and fuel consumption (gal): ";
    cin >> mile >> gallon;
    cout << "Input 0 British system display" << endl;
    cout << "Input 1 European style display" << endl;
    cin >> mode;
    if (mode == 0)
        cout << mile / gallon << " miles per gallon" << endl;
    else
    {
        cout << gallon * GALLON_LITER / (mile * MILE_METER) * 100;
        cout << " liter per 100 kilometers" << endl;
    }

    system("pause");
    return 0;
}