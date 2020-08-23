#include <iostream>

using namespace std;

struct CandyBar
{
    char name[20];
    double quality;
    int calorie;
};

int main()
{
    CandyBar snack = {
        "Mocha Munch",
        2.3,
        350
    };

    cout << "Name : " << snack.name << endl;
    cout << "Quality : " << snack.quality << endl;
    cout << "Calorie : " << snack.calorie << endl;

    system("pause");
    return 0;
}