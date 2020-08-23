#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data");
	vector<string> vs;

	istream_iterator<string> in(fin), eof;
	ostream_iterator<string> out(cout, " ");

	while (in != eof)
	{
		vs.push_back(*in);
		out = *in++;
	}
	cout << endl;

	fin.close();

	system("pause");
	return 0;
}