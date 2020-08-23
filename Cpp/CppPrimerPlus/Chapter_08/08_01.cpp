#include <iostream>

using namespace std;

int count = 0;

void print(const char* str, int n = 0);

int main()
{
	const char* str = "hello!";

	print(str);
	print(str, 1);
	print(str, 0);
	print(str, -1);

	system("pause");
	return 0;
}


void print(const char* str, int n)
{
	static int count = 0;

	count++;

	if (n == 0)
		cout << str << endl;
	else
		for (int i = 0; i < count; i++)
			cout << str << endl;
	cout << "----------" << endl;
}