#include <iostream>
#include <regex>
#include <string>

using namespace std;
 
int main()
{
	string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	string fmt = "$2.$5.$7";
	regex r(pattern);
	string s;

	while (getline(cin, s))
	{
		smatch result;
		regex_search(s, result, r);
		if (!result.empty())
			cout << result.suffix()<< endl;
		else
			cout << "No match" << endl;
	}

	system("pause");
	return 0;
}