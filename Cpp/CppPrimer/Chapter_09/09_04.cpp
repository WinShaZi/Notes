#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool find_num(const vector<int> &vi, const int i)
{
    return find(vi.begin(), vi.end(), i) != vi.end();
}

int main()
{
    vector<int> vi{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;

    while (cin >> i)
        cout << (find_num(vi, i) ? "true" : "false") << endl;

    system("pause");
    return 0;
}