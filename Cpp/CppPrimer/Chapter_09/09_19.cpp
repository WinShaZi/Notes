#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list<string> ls;
    string st;

    while (cin >> st)
        ls.push_back(st);

    list<string>::iterator ls_iter = ls.begin();

    while (ls_iter != ls.end())
        cout << *ls_iter++ << endl;

    system("pause");
    return 0;
}