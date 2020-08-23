#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> vs;

    vs.reserve(128);

    while (vs.size() < vs.capacity())
        vs.push_back("string");

    cout << vs.size() << ' ' << vs.capacity() << endl;

    vs.push_back("string");
    cout << vs.size() << ' ' << vs.capacity() << endl;

	system("pause");
	return 0;
}