#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

string &change(string &s, const string &oldVal, const string &newVal)
{
    int old_size = oldVal.size();
    auto iter_s = s.begin();
    auto iter_old = oldVal.begin();
    auto iter_new = newVal.begin();

    for (iter_s; iter_s <= (s.end() - oldVal.size() + 1); ++ iter_s) 
    {

        if (s.substr((iter_s - s.begin()), old_size) == oldVal) 
        {
            iter_s = s.erase(iter_s, iter_s+  old_size);
            iter_s = s.insert(iter_s, newVal.begin(), newVal.end());
        }
    };

    return s;
}

int main()
{
    string s("tho the tho");
    string oldVal("tho");
    string newVal("though");

    cout << change(s, oldVal, newVal) << endl;

	system("pause");
	return 0;
}