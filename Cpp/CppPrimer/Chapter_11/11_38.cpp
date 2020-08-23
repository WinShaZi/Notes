#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

void word_transform(ifstream &map_filem, ifstream &input);
unordered_map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const unordered_map<string, string> &m);

int main()
{
	ifstream map_file("data", std::ios::in);
	ifstream input("alter", std::ios::in);

	if (map_file.is_open() && input.is_open())
		word_transform(map_file, input);
	else
		cerr << "Can't open files" << endl;
	
	
	map_file.close();
	input.close();
	
	system("pause");
	return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;

	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;

		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else 
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else 
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);

	if (map_it != m.cend())
		return map_it->second;
	else 
		return s;
}