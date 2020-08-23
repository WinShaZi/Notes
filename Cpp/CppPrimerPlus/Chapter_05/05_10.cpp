#include <iostream>

using namespace std;

int main()
{
	int num;

	cout << "Enter number of rows : ";
	cin >> num;
	for (int line = 1; line <= num; line++)
	{
		for (int i = num; i > line; i--)
			cout << '.';
		for (int j = line; j > 0; j--)
			cout << '*';
		cout << endl;
	}

	system("pause");
	return 0;
}