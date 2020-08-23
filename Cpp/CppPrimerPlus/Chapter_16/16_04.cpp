#include <iostream>
#include <algorithm>

using namespace std;

int reduce(long ar[], int n);

int main()
{
	long ar[] = { 3,1,2,5,4,5,8,7,6,1 };
	
	int count = reduce(ar, sizeof(ar) / sizeof(long));
	for (int i = 0; i < count; i++)
		cout << ar[i] << endl;

	system("pause");
	return 0;
}

int reduce(long ar[], int n)
{
	sort(ar, ar + n);
	long* p = unique(ar, ar + n);

	return int(p - ar);
}