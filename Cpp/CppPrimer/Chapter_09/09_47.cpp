#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void find_number(const string &st)
{
    unsigned i = 0;

	while ((i = st.find_first_of("0123456789", i)) != string::npos)
    {
        cout << st[i] << ' ';
        i++;
    }
    cout << endl;
}

void find_char(const string &st)
{
    unsigned i = 0;

	while ((i = st.find_first_not_of("0123456789", i)) != string::npos)
    {
        cout << st[i] << ' ';
        i++;
    }
    cout << endl;
}

int main()
{
	const string st("ab2c3d7R4E6");

    find_number(st);
    find_char(st);

	system("pause");
	return 0;
}