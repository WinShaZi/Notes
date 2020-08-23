#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class PrintString
{
private:
	vector<string> vs;
	istream &is;
	string st;
public:
	PrintString (istream &i = cin) : is(i) 
	{ 
		while (getline(is, st)) 
			vs.push_back(st); 
	}
	
	friend ostream & operator<<(ostream &os, const PrintString &ps)
	{
		for (auto n : ps.vs)
			os << n << endl;
		return os;
	}
};

int main()
{
	PrintString ps(cin);

	cout << ps << endl;

	system("pause");
	return 0;
}