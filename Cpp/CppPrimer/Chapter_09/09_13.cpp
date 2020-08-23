#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> li{ 1, 2, 3, 4, 5 };
    vector<int> vi{ 1, 2, 3, 4, 5 };

    vector<double> vd_li(li.begin(), li.end());
    vector<double> vd_vi(vi.begin(), vi.end());

    for (auto n : vd_li)
        cout << n << ' ';
    cout << endl;

    for (auto n : vd_vi)
         cout << n << ' ';
    cout << endl;

    system("pause");
    return 0;
}