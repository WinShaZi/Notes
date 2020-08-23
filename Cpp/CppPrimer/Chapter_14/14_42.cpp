#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> vi{ 1, 11, 111, 1111, 11111 };
    cout << count_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 1024)) << endl;

	vector<string> vs{ "poop", "poo", " poop", "po" };
	cout << *find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "poop")) << endl;

	transform(vi.begin(), vi.end(),vi.begin(), bind(multiplies<int>(), _1, 2));
	for_each(vi.begin(), vi.end(), [](const int &i) { cout << i << ' ';});
	cout << endl;

	system("pause");
	return 0;
}