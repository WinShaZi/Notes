#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
int reduce(T ar[], int n);

int main()
{
	long ar[] = { 3,1,2,5,4,5,8,7,6,1 };
	string st[4] = { "are","ok","are","you" };

	int count = reduce(ar, sizeof(ar) / sizeof(long));
	for (int i = 0; i < count; i++)
		cout << ar[i] << endl;
	count = reduce(st, 4);
	for (int i = 0; i < count; i++)
		cout << st[i] << endl;

	system("pause");
	return 0;
}

template<class T>
int reduce(T ar[], int n)
{
	sort(ar, ar + n);
	T* p = unique(ar, ar + n);

	return int(p - ar);
}