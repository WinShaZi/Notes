#include <iostream>

using namespace std;

const int SIZE = 20;

struct message
{
    char first[SIZE];
    char last[SIZE];
    char grade;
    int age;
}s1;

int main()
{
    message * ps = &s1;

    cout << "What is your first name? : ";
    cin.getline(ps->first, SIZE);
    cout << "What is your last name? : ";
    cin.getline(ps->last, SIZE);
    cout << "What letter grade do you deserve? : ";
    cin.get(ps->grade);
    cout << "What is your age? : ";
    cin >> ps->age;

    cout << "Name : " << ps->last << ", " << ps->first << endl;
    cout << "Grade : " << ps->grade << endl;
    cout << "Age : " << ps->age << endl;

    system("pause");
    return 0;
}