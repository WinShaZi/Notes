#include<iostream>
#include<cstring>

using namespace std;

int main() 
{
	char word[20];
	int num = 0;

	cout << "Enter words (to stop, type the word done):" << endl;
	while (cin >> word && strcmp(word, "done"))
		num++;
	cout << num << endl;

	system("pause");
	return 0;
}