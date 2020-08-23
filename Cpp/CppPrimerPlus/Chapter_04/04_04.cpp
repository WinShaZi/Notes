#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string first, last, str;

    cout << "Enter your first name : ";
    cin >> first;
    cout << "Enter your last name : ";
    cin >> last;
    str = last + ", " + first;
    cout << "Here's the information in a single string : ";
    cout << str << endl;

    system("pause");
    return 0;
}