#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch[100];
	int i = 0;

	while ((ch[i++] = cin.get()) != '@');
	for (int j = 0; j < i - 1; j++)
	{
		if (isdigit(ch[j]))
			continue;
		if (isalpha(ch[j]))
			ch[j] = islower(ch[j]) ? toupper(ch[j]) : tolower(ch[j]);
		cout << ch[j];
	}
	cout << endl;

	system("pause");
	return 0;
}