#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

void ShowStr(const string& s) { cout << s << endl; }
void GetStrs(ifstream& fi, vector<string>& s);

class Store
{
private:
	ofstream& fou;
public:
	Store(ofstream& os) :fou(os) {};
	void operator()(const string& s)
	{
		size_t len = s.size();
		fou.write((char*)& len, sizeof(size_t));
		fou.write(s.data(), len);
	}
};

int main()
{
	vector<string>vostr;
	string temp;

	cout << "Enter strings(empty line to quit) : " << endl;
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);

	cout << "Here is your input." << endl;
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("string.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string>vistr;
	ifstream fin("string.dat", ios_base::in | ios_base::binary);

	if (!fin.is_open())
	{
		cerr << "Could not open file" << endl;
		exit(EXIT_FAILURE);
	}

	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file : " << endl;
	for_each(vostr.begin(), vostr.end(), ShowStr);

	system("pause");
	return 0;
}

void GetStrs(ifstream& fi, vector<string>& ve)
{
	size_t len;

	while (fi.read((char*) & len, sizeof(size_t)))
	{
		char* st = new char[len + 1];
		fi.read(st, len);
		st[len + 1] = '\0';
		ve.push_back(st);
	}
}