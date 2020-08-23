#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main()
{
    list<int> li{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    deque<int> di1;
    deque<int> di2;
    string st;

    for (auto n : li)
    {
        if (n % 2 == 0)
            di1.push_back(n);
        else
            di2.push_back(n);
    }

    for (auto n : di1)
        cout << n << endl;
    for (auto n : di2)
        cout << n << endl;

    system("pause");
    return 0;
}