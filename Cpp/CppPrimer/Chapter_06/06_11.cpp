#include <iostream>

using namespace std;

void reset(int &i)
{
	i = 0;
}

int main()
{
	int i = 1;

	cout << i << endl;

	reset(i);

	cout << i << endl;
	

	system("pause");
	return 0;
}