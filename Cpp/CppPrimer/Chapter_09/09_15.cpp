#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1(10, 1);
    vector<int> v2(5, 1);

    cout << (v1 > v2 ? "v1" : "v2") << endl;

    system("pause");
    return 0;
}