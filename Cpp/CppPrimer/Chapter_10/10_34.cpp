#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> vs{"you", "can", "you", "up", "no", "can", "no", "bb"};

	for (auto iter = vs.crbegin(); iter != vs.crend(); iter++)
		cout << *iter << ' ';
	cout << endl;


	system("pause");
	return 0;
}