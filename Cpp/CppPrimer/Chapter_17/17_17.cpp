#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("data");
	if (!fin)
	{
		cerr << "Can't open file" << endl;
		exit(1);
	}

	string p("[^c]ei");
	p = "[[:alpha:]]*" + p + "[[:alpha:]]*";
	regex reg(p, regex::icase);
	string str, temp;

	while (getline(fin, temp))
		str += temp + ' ';

	for (sregex_iterator it(str.begin(), str.end(), reg), end_it; it != end_it; ++it)
		cout << it->str() << endl;
 
	system("pause");
	return 0;
}