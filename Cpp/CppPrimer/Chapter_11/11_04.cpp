#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

bool is(char ch)
{
    return ispunct(ch);
}

int main()
{
	map<string, size_t> word_count;
    string word;

    while (cin >> word) 
    {
        for (auto& ch : word) 
            ch = tolower(ch);
        word.erase(remove_if(word.begin(), word.end(), is), word.end());
        ++ word_count[word];
    }

    for (const auto& w : word_count) {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ?  " times" : " time.")  << endl;
    }

	
	system("pause");
	return 0;
} 