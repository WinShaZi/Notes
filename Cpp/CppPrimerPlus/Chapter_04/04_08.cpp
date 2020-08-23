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
    message * pi = new message;

    cout << "Input pizza's diameter : ";
    cin >> pi->diameter;
    cout << "Input pizza's quality : ";
    cin >> pi->quality;
    cin.get();
    cout << "Input pizza's name : ";
    cin.getline(pi->name, 20);

    cout << pi->name << ' ' << pi->diameter << ' ' << pi->quality << endl;
    delete pi;

    system("pause");
    return 0;
}