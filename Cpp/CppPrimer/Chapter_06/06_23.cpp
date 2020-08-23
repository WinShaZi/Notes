#include <iostream>

using namespace std;

void print(const int i)
{
    cout << i << endl;
}

void print(const int j[], int n)
{
    for (int i = 0; i < n; i++)
        cout << j[i] << ' ';
    cout << endl;
}

int main()
{
    int i = 1;
    int j[] = { 1, 2 };

    print(i);
    print(j, sizeof(j) / sizeof(int));

    system("pause");
	return 0;
}