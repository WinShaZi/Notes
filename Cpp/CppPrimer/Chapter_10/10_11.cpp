#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &vs)
{
	sort(vs.begin(), vs.end());
	auto end = unique(vs.begin(), vs.end());
	vs.erase(end, vs.end());
	stable_sort(vs.begin(), vs.end(), isShorter);
}

int main()
{
	vector<string> vs{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

	for (auto n : vs)
		cout << n << ' ';
	cout << endl;


	elimDups(vs);
	
	for (auto n : vs)
		cout << n << ' ';
	cout << endl;
	
	system("pause");
	return 0;
} 