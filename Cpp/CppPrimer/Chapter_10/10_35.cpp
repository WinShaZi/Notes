#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> vs{"you", "can", "you", "up", "no", "can", "no", "bb"};

	for (auto iter = vs.cend(); iter != vs.cbegin(); iter--)
		cout << *(iter - 1) << ' ';
	cout << endl;


	system("pause");
	return 0;
}