#include <iostream>

using namespace std;

int main()
{
	int i = 10;

	auto n = [&i]()->bool { return --i > 0 ? true : false; };

	while (n())
		cout << i << endl;

	system("pause");
	return 0;
}