#include <iostream>

using namespace std;

int is_big(const int *num, const int n)
{
    return *num > n ? *num : n;
}

int main()
{
    int i = 10;
    int *num = &i;
    int n = 20;

    cout << is_big(num, n) << endl;

    system("pause");
	return 0;
}