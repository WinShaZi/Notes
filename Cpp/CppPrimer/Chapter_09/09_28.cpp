#include <iostream>
#include <forward_list>
#include <string>
#include <algorithm>

using namespace std;

void find_str(forward_list<string> &fls, const string &str1, const string &str2)
{
    auto fls_iter = find(fls.begin() ,fls.end(), str1);
    auto fls_last = fls.begin();
    auto temp = fls.begin();

    while(1)
    {
        if (++temp == fls.end())
            break;
        ++fls_last;
    }
    
    if (fls_iter == fls.end())
    {
        fls.insert_after(fls_last, str2);
    }
    else
    {
        fls.insert_after(fls_iter, str2);
    }
    
}

int main()
{
	forward_list<string> fls{ "C", "C++", "Primer", "Plus" };
    string str1, str2;

    if (cin >> str1 >> str2)
        find_str(fls, str1, str2);

    for (auto n : fls)
        cout << n << endl;

	system("pause");
	return 0;
}