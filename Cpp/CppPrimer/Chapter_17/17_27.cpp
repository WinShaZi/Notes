#include <iostream>
#include <string>
#include <regex>
 
using namespace std;

int main()
{
	string p = "(\\d{5})(\\d{4})";
	regex reg(p);
	string fmt = "$1-$2";
	smatch m;
	string n;
	while (getline(cin, n) && n != "q")
		cout << regex_replace(n, reg, fmt, std::regex_constants::format_no_copy) << endl;

	system("pause");
	return 0;
}