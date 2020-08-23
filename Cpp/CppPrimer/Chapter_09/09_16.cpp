#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

string max_vi_li(const vector<int> &vi, const list<int> &li)
{
    auto vi_beg = vi.begin();
    auto vi_end = vi.end();
    auto li_beg = li.begin();
    auto li_end = li.end();

    while (1)
    {
        if (*vi_beg < *li_beg)
            return "list";
        else if (*vi_beg > *li_beg)
            return "vector";
        
        vi_beg++;
        li_beg++;

        if (vi.size() == li.size())
            return "equal";

        if (vi_beg == vi_end)
            return "list";
        else if (li_beg == li_end)
            return "vector";
    }
}

int main()
{
    vector<int> vi(10, 1);
    list<int> li(10, 0);

    cout << max_vi_li(vi, li) << endl;

    system("pause");
    return 0;
}