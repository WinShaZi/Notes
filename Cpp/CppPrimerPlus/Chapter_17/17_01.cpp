#include <iostream>

using namespace std;

int main()
{
	char ch;
	int count = 0;

	cout << "Input : ";
	while (cin.get(ch) && ch != '$')
		count++;
	cin.putback(ch);
	cout << count << endl;

	system("pause");
	return 0;
}