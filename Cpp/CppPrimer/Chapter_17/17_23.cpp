
#include <iostream>
#include <string>
#include <regex>
 
int main()
{
	using namespace std;
	string s = "(\\d{5})([-])?(\\d{4})?";
	string num;
	regex reg(s);
	smatch m;

	while (getline(cin, num) && num != "q")
	{
		for (sregex_iterator it(num.begin(), num.end(), reg), end_it; it != end_it; ++it)
		{
			if ((*it)[3].matched)
				cout << it->str();
			else
				cout << it->str(1);
			cout << endl;
		}
	}
	system("pause");
	return 0;
}