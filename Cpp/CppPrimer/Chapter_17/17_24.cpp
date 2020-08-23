#include <iostream>
#include <regex>
#include <string>

using namespace std;
 
int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([[:blank:]]*)?(\\d{3})([[:blank:]]*)?(\\d{4})";
	regex reg;

	try 
	{
		reg.assign(phone);
	}
	catch (regex_error e) 
	{
		cout << e.what() << "\ncode: " << e.code();
	}
	
	string fmt = "$2.$5.$7";
	smatch m;
	string s;

	while (getline(cin, s) && s != "q")
		cout << regex_replace(s, reg, fmt) << endl;

	system("pause");
	return 0;
}