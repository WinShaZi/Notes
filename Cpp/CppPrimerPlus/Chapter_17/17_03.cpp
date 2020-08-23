#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "Usage : " << argv[1] << " filename" << endl;
		exit(EXIT_FAILURE);
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	if (!fin.is_open() || !fout.is_open())
	{
		cerr << "Can't open \"" << argv[1] << "\" or \"" << argv[2] << "\" files" << endl;
		exit(EXIT_FAILURE);
	}
	string temp;

	while (!fin.eof() && getline(fin, temp))
		fout << temp << '\n';
	fin.close();
	fout.close();

	system("pause");
	return 0;
}