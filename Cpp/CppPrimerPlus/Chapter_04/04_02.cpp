#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string name, dessert;

    cout << "Enter your name : " << endl;
    cin >> name;
    cout << "Enter your favorite dessret : " << endl;
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << endl;

    system("pause");
    return 0;
}