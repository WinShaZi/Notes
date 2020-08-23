#include <iostream>
#include <vector>

using namespace std;

void show(const vector<int> &vi, int n)
{
    if (n > 0)
        show(vi, --n);
    cout << vi[n] << endl;
}

int main()
{
	vector<int> vi(10, 100);

	show(vi, vi.size() - 1);

	system("pause");
	return 0;
}