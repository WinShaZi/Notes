#include <iostream>
#include<string>
#include <regex>

using namespace std;

bool valid(const smatch& m);

int main()
{
	string phone = "(\\()?(\\d{4})([-. ])?(\\d{4})([-. ]?)(\\d{3}(\\))?)";
	regex r(phone);
	smatch m;
	string s;
	bool valid_record;

	while (getline(cin, s))
	{
		valid_record = false;

		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			valid_record = true;

			if (valid(*it))
				cout << "valid phone number: " << it->str() << endl;
			else
				cout << "invalid phone number: " << it->str() << endl;
		}

		if (!valid_record)
			cout << "invalid record!" << endl;
	}

	system("pause");
	return 0;
}

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched
		&& (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched
		&& m[4].str() == m[6].str();
}