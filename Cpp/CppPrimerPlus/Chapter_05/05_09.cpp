#include<iostream>
#include<string>

using namespace std;

int main() 
{
    string word;
	int num = 0;

	cout << "Enter words (to stop, type the word done):" << endl;
	while (cin >> word && word != "done")
		num++;
	cout << num << endl;

	system("pause");
	return 0;
}