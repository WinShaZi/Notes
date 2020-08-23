#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int> &vi)
{
    for (auto &n : vi)
        n *= n;
}

void show(const vector<int> vi)
{
    for (auto n : vi)
        cout << n << endl;
    cout << endl;
}

int main()
{
    vector<int> vi(10, 10);

    show(vi);
    multiply(vi);
    show(vi);

    system("pause");
	return 0;
}