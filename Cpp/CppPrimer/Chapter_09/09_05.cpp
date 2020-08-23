#include <iostream>
#include <vector>

using namespace std;

int find_num(const vector<int> &vi, const int i)
{
    for (auto n : vi)
        if (i == n)
            return i;

    return ~i;
}

int main()
{
    vector<int> vi{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;

    while (cin >> i)
        cout << (find_num(vi, i) == i ? i : ~i) << endl;

    system("pause");
    return 0;
}