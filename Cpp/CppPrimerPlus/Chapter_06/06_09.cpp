#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int SIZE = 60;

int main()
{
	char filename[SIZE];
	string str;
	int num = 0;
	ifstream infile;

	cout << "Input name of data file : ";
	cin.getline(filename, SIZE);
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating." << endl;
		exit(EXIT_FAILURE);
	}

	while (infile.good())
	{
		infile >> num;
		infile.get();
		getline(infile, str);
		cout << num << endl << str << endl;
	}

	if (infile.eof())
		cout << "End of file reached." << endl;
	else if (infile.fail())
		cout << "Input terminated for data mismatch" << endl;
	else
		cout << "Input terminated for unkown reason" << endl;

	infile.close();

	system("pause");
	return 0;
}