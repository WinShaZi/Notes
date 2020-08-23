#include <iostream>

using namespace std;

int get_size()
{
	static int i = -10;

	return i++;
}

int main()
{
	int sz;

	do
	{
		sz = get_size();
	} while(sz <= 0);

	system("pause");
	return 0;
}