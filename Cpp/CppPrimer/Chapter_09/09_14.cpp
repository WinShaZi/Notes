#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<string> vs;
    list<const char *> lc(10, "list");

    vs.assign(lc.begin(), lc.end());

    for (auto n : vs)
        cout << n << endl;

    system("pause");
    return 0;
}