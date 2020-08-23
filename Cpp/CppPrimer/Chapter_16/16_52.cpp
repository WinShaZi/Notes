#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

template <typename T, typename...Args>
void foo(const T &t, const Args &...rest)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) <<  endl;
}
 
int main()
{
    int i = 0, j = 1;
    double d = 3.14;
    string s = "hello";
    foo(i, s, 42, d);
    cout << endl;
    foo(s, 42, "hi");
    cout << endl;
    foo(d, s);
    cout << endl;
    foo("hi");
    cout << endl;
    foo(s, i, j);

	system("pause");
    return 0;
}