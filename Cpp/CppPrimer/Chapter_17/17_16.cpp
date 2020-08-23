#include <iostream>
#include <string>
#include <regex>

using namespace std;
 
int main()
{
	regex reg("[^c]ei");
	string str;
	smatch m;

	while (cin >> str && str != "q")		
	{
		if (regex_search(str, m, reg))
			cout << str << " is ok" << endl;
		else
			cout << str << " is not ok" << endl;
	}
 
	system("pause");
	return 0;
}