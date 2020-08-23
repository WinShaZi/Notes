#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

int main()
{
    deque<string> ds;
    string st;

    while (cin >> st)
        ds.push_back(st);

    deque<string>::iterator ds_iter = ds.begin();

    while (ds_iter != ds.end())
        cout << *ds_iter++ << endl;

    system("pause");
    return 0;
}