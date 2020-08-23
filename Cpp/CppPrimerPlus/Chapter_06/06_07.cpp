#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	char str[20];
	int vowel = 0;
	int consonants = 0;
	int others = 0;

	cout << "Enter words (q to quit):" << endl;
	while (cin >> str)
	{
		char ch = tolower(str[0]);
        
		if (strcmp(str, "q") == 0)
			break;
		if (isalpha(ch))
		{
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowel++;
				break;
			default:
				consonants++;
			}
		}
		else
			others++;
	}
	cout << vowel << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;

	system("pause");
	return 0;
}