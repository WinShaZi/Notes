#include <iostream>
#include <string>

using namespace std;

const int ArSize = 10;

void strcount(const string str);

int main()
{
    string input;

    cout << "Enter a line : " << endl;
	while (getline(cin, input) && input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit): " << endl;
    }
    cout << "Bye\n";

    system("pause");
    return 0;
}

void strcount(const string str)
{
    static int total = 0;
    int i = 0;
    int count = 0;

    cout << "\"" << str <<"\" contains ";
    while (str[i++])
        count++;
    total += count;
    cout << count << " characters" << endl;
    cout << total << " characters total" << endl;
}
