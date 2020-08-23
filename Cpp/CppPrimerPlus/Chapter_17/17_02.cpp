#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cerr << "Usage : " << argv[1] << " filename" << endl;
		exit(EXIT_FAILURE);
	}
	ofstream fout(argv[1]);
	if (!fout.is_open())
	{
		cerr << "Can't open \"" << argv[1] << "\" file" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 2; i < argc; i++)
		fout << argv[i];
	fout.close();

	system("pause");
	return 0;
}