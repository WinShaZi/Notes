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
	CandyBar * snack = new CandyBar[3] {
        { "Mocha Munch", 2.3, 350 } ,
        { "Mocha Munci", 2.4, 360 } ,
        { "Mocha Munck", 2.5, 370 } 
    };

	cout << snack[0].name << " " << snack[0].quality << " " << snack[0].calorie << endl;
	cout << snack[1].name << " " << snack[1].quality << " " << snack[1].calorie << endl;
	cout << snack[2].name << " " << snack[2].quality << " " << snack[2].calorie << endl;

    delete [] snack;

	system("pause");
	return 0;
}