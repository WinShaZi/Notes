#include <iostream>

using namespace std;

struct message
{
    char name[20];
    double diameter;
    double quality;
};

int main()
{
    message pizza;

    cout << "Input pizza's name : ";
    cin.getline(pizza.name, 20);
    cout << "Input pizza's diameter : ";
    cin >> pizza.diameter;
    cout << "Input pizza's quality : ";
    cin >> pizza.quality;

    cout << pizza.name << ' ' << pizza.diameter << ' ' << pizza.quality << endl;

    system("pause");
    return 0;
}