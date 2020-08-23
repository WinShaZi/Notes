#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <random>

using namespace std;

map<string, string> buildmap(ifstream &ifile)
{
	map<string, string> temp;
	string str, f, s;
	while (getline(ifile, str))
	{
		istringstream sst(str);
		sst >> f >> s;
		temp[f] = s;
	}
	return temp;
}
string trans(const string &s, map<string, string> &m)
{
	auto temp = m.find(s);
	if (temp != m.end())
		return m[s];
	else
		return s;
}
string trans_random(const string &s, map<string, string> &m)
{
	auto temp = m.find(s);
	if (temp != m.end())
		return (m[s]+"!");
	else
		return s;
}
int main()
{
	ifstream ifpw("data1"), iftxt("data1");

	if (!ifpw && !iftxt)
	{
		cerr << "open file error!\n";
		exit(1);
	}

	map<string, string> pw(buildmap(ifpw));
	string temp, f;
	default_random_engine e;
	bernoulli_distribution b;
	bool t;

	while (getline(iftxt, temp))
	{
		istringstream iss(temp);
		while (iss >> f)
		{
			t = b(e);
			if(t)
				cout << trans_random(f, pw) << " ";
			else
				cout << trans(f, pw) << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}