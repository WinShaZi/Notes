#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;
 
struct PersonInfo 
{
	string name;
	vector<string> phones;
};

bool valid(const smatch& m);
void read_record(istream& is, ostream& ou, vector<PersonInfo>& people);
void format_record(ostream& os, const string& str, PersonInfo& people);
string format(const string &num) { return num; }

int main()
{
	vector<PersonInfo> people;
	ifstream fin("data");
	
	if (fin.is_open())
	{
		ofstream fout("_data", ofstream::trunc);
		read_record(fin, fout, people);
	}
	else
		cout << "Can't open file" << endl;
	
	fin.close();

	system("pause");
	return 0;
}

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched
		&& (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched
		&& m[4].str() == m[6].str();
}

void read_record(istream& is,ostream& os, vector<PersonInfo>& people)
{
	string line, word;
	while (getline(is, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;

		while (getline(record, word))
			format_record(os,word,info);
		people.push_back(info);
	}
	return;
}

void format_record(ostream& os, const string& phones, PersonInfo& people)
{
	string phone =
		"(\\()?(\\d{4})(\\))?([-.]|\\s*)?(\\d{4})([-.]|\\s*)?(\\d{3})\\b";
	regex r(phone);
	ostringstream formatted, badNums; 
	for (sregex_iterator it(phones.begin(), phones.end(), r), end_it;
	it != end_it; ++it)
	{
		if (!valid(*it))
			badNums << " " << it->str();
		else
		{
			formatted << " " << format(it->str());
			people.phones.push_back(it->str());
		}
	}

	if (badNums.str().empty())
		os << people.name << " " << formatted.str() << endl;
	else
		cerr << "input error: " << people.name << " invalid number(s) " << badNums.str() << endl;
}