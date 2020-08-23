#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> vs{ "1", "3", "5", "7", "9" };
    float sum = 0;

    for (auto n : vs)
        sum += stof(n);
    
    cout << sum << endl;

	system("pause");
	return 0;
}