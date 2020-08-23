#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin1("data1.txt"), fin2("data2.txt");
	ofstream fout("data.txt");

	if (!fin1.is_open() || !fin2.is_open() || !fout.is_open())
	{
		cerr << "Can't open file" << endl;
		exit(EXIT_FAILURE);
	}
	string temp1, temp2;

	while (!fin1.eof() || !fin2.eof())
	{
		if (!fin1.eof() && getline(fin1, temp1))
			fout << temp1 << ' ';
		if (!fin2.eof() && getline(fin2, temp2))
			fout << temp2;
		fout << '\n';
	}
	fin1.close();
	fin2.close();
	fout.close();
	cout << "Done!" << endl;

	system("pause");
	return 0;
}