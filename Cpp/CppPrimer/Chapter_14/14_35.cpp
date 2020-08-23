#include <iostream>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

class PrintString
{
private:
	istream &is;
	string st;
public:
	PrintString (istream &i = cin) : is(i) { getline(is, st); }
	string getString() const { return st; }
};

int main()
{
	PrintString ps(cin);
	cout << ps.getString() << endl;

	system("pause");
	return 0;
}