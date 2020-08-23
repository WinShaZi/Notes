#include <iostream>
#include <vector>

using namespace std;

void show(const vector<int> &vi)
{
    for (auto n : vi)
        cout << n << ' ';
    cout << endl;
}

int main()
{
    vector<int> v1(5);
    vector<int> v2(5, 5);
    vector<int> v3(v2);
    vector<int> v4 = v3;
    vector<int> v5{ 1, 2, 3, 4, 5};
    vector<int> v6 = { 1, 2, 3, 4, 5};
    vector<int> v7(v6.begin(), v6.end());

    vector<vector<int>> vvi{ v1, v2, v3, v4, v5, v6, v7 };

    for (auto n : vvi)
        show(n);

    system("pause");
    return 0;
}