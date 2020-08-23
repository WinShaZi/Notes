#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream finout("data");
	if (!finout)
	{
		cout << "Can't open file";
		exit(1);
	}

	string st;

	while (getline(finout, st))
		cout << st << endl;
	finout.close();

	system("pause");
	return 0;
}