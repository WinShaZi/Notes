#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
    Foo (std::vector<int>& ivec) : data(ivec) {}
    Foo sorted() &&;
    Foo sorted() const &;
    std::vector<int>& getData() { return data; }
private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    cout << "right value sorted." << endl;
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "left value sorted." << endl;
    Foo ret (*this);
    sort (ret.data.begin(), ret.data.end());
    return ret;
}

int main()
{
    vector<int> ivec = {1, 2, 5, 4, 7};
    Foo f1(ivec);
    Foo f2 = f1.sorted();

    for (auto i : f2.getData())
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}