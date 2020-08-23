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

	while (fin >> temp)
		str += temp + ' ';

	vector<string> vec{ 
		"albeit","beige","feint","heir","reign","their", "neighbor",
		"counterfeit","foreign","inveigh","rein","veil","deign",
		"forfeit","inveigle","seize","veineiderdown","freight",
		"leisure","skein","weigheight","heifer","neigh","sleigh",
		"weighteither","height","neighbour","sleight","weirfeign",
		"heinous neither surfeit weird" 
	};

	for (sregex_iterator it(str.begin(), str.end(), reg), end_it; it != end_it; ++it)
	{
		if (find(vec.begin(), vec.end(), it->str()) != vec.end())
				continue;
		cout << it->str() << endl;
	}

	fin.close();

	system("pause");
	return 0;
}