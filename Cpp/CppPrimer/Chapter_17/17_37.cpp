#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data");
	if (!fin)
	{
		cout << "Can't open file";
		exit(1);
	}

	char ar[100];

	while (fin.getline(ar, 99))
		cout << ar << endl;
	fin.close();

	system("pause");
	return 0;
}