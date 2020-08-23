#include <iostream>
#include <vector>
#include <cassert>

/*
#ifndef NDEBUG
#define NDEBUG
#endif
*/ 

using namespace std;

void show(const vector<int> &vi, int n)
{
    if (n > 0)
        show(vi, --n);

#ifndef NDEBUG
	cout << "vector size: " << vi.size() << endl;
#endif

    cout << vi[n] << endl;
}

int main()
{
	vector<int> vi(10, 100);

	show(vi, vi.size() - 1);

	system("pause");
	return 0;
}