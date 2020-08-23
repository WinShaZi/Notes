#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	map<string, size_t> word_count;
    string word;

    while (cin >> word) 
        ++word_count[word];

    for (auto n : word_count) 
        cout << n.first << " occurs " << n.second << (n.second > 1 ?  " times" : " time.")  << endl;

	
	system("pause");
	return 0;
} 