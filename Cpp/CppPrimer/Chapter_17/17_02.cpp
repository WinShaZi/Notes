#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>
#include <string>

using namespace std;


int main()
{
	tuple<string, vector<string>, pair<string, int>> tt{ "string", { "string" }, { "string", sizeof("string") } };


	system("pause");
	return 0;
}