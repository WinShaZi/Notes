#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char first[20];
    char last[20];
    char str[40];

    cout << "Enter your first name : ";
    cin >> first;
    cout << "Enter your last name : ";
    cin >> last;
    strcpy(str, last);
    strcat(str, ", ");
    strcat(str, first);
    cout << "Here's the information in a single string : ";
    cout << str << endl;

    system("pause");
    return 0;
}