#include <iostream>

using namespace std;

void change(int *i, int *j)
{
    *i ^= *j ^= *i ^= *j;
}

int main()
{
    int i = 10;
    int j = 20;

    change(&i, &j);

    cout << i << ' ' << j << endl;

    system("pause");
	return 0;
}