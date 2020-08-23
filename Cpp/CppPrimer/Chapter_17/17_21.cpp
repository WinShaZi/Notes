
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
 
struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};
bool valid(const std::smatch &m);
bool read_record(std::istream &is, std::vector<PersonInfo> &people);
void format_record(std::ostream &os, const std::vector<PersonInfo> &people);
 
int main()
{
	using namespace std;
	vector<PersonInfo> people;
	ifstream fin("data");

	if (read_record(fin, people))
	{
		cout << "Input output file name:";
		string outname;
		cin >> outname;
		ofstream fout(outname, ofstream::trunc); 
		format_record(fout, people);
	}
	else
		cout << "Can't open file" << endl;
	
	fin.close();
 
	system("pause");
	return 0;
}
 
bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4] == " ");
	else
		return !m[3].matched&&m[4].str() == m[6].str();
}

bool read_record(std::istream &is, std::vector<PersonInfo> &people)
{
	if (is)
	{
		std::string line, word;
		while (getline(is, line))
		{
			PersonInfo info;
			std::istringstream record(line);
			record >> info.name;
			while (record >> word)		
				info.phones.push_back(word);
			people.push_back(info);
		}
		return true;
	}
	else
		return false;
}

void format_record(std::ostream &os, const std::vector<PersonInfo> &people)
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	std::regex reg;
	try {
		reg.assign(phone);
	}
	catch (std::regex_error e)
	{
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}
	std::smatch m;
	for (const auto &x : people)
	{
		std::ostringstream formatted, badNums;
		for (const auto &n : x.phones)
		{
			for (std::sregex_iterator it(n.begin(), n.end(), reg), end_it; it != end_it; ++it)
			{
				if (!valid(*it))
					badNums << " " << n;
				else
					formatted << " " << n;
			}
		}
		if (badNums.str().empty())
			os << x.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "file error: " << x.name << " invalid number " << badNums.str() << std::endl;
	}
}