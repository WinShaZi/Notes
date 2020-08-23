#include <iostream>
#include <string>

using namespace std;

struct car 
{
	string name;
	int year;
};

int main() 
{
	int num;
	cout << "How many cars do you wish to catalog? : ";
	cin >> num;
	car* ps = new car[num];
	for (int i = 0; i < num; i++) 
	{
        while(cin.get() != '\n');
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make : ";
		getline(cin, ps[i].name);
		cout << "Please enter the year made : ";
		cin >> ps[i].year;
	}
	cout << "Here is your collect : " << endl;
	for (int i = 0; i < num; i++)
		cout << ps[i].year << ' ' << ps[i].name << endl;
	delete ps;

	system("pause");
	return 0;
}