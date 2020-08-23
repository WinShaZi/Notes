#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    vector<int> vi(ia, ia + 12);
    list<int> li(ia, ia + 12);

    auto vi_iter = vi.begin();

    while (vi_iter != vi.end())
    {
        if (*vi_iter % 2 == 0)
        {
            swap(*vi_iter, *(vi.end() - 1));
            vi.pop_back();
        }
            vi_iter++;
    }
    sort(vi.begin(), vi.end());

    auto li_iter = li.begin();

    while (li_iter != li.end())
    {
        if (*li_iter % 2 == 1)
            li_iter = li.erase(li_iter);
        else 
            li_iter++;
    }

    for (auto n : vi)
        cout << n << ' ';
    cout << endl;
    for (auto n : li)
        cout << n << ' ';
    cout << endl;

    system("pause");
    return 0;
}