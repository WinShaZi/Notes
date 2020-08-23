#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("data");
	ofstream fout1("data1"), fout2("data2");
	istream_iterator<int> in(fin), eof;
	ostream_iterator<int> out1(fout1, " ");
	ostream_iterator<int> out2(fout2, "\n");

	while (in != eof)
	{
		if (*in % 2)
			out1 = *in;
		else 
			out2 = *in;
		in++;
	}
	fout1.close();
	fout2.close();

	system("pause");
	return 0;
}