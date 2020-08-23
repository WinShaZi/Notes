#include <iostream>

using namespace std;

bool have_upper(const string &st)
{
    for (auto c : st)
        if (isupper(c))
            return true;

    return false;
}

string up_low(string &st)
{
    for (auto &c : st)
        if (isupper(c))
            c = islower(c);
    
    return st;
}

int main()
{
    string st(10, 'A');

    cout << st << endl;
    cout << (have_upper(st) ? "true" : "false") << endl;
    up_low(st);
    cout << st << endl;

    system("pause");
	return 0;
}