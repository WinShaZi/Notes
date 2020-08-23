#include <iostream>
#include <string>
#include <vector>
#include <random>
 
using namespace std;

vector<unsigned> bad_ranVec()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;

	for (size_t i = 0; i < 10; i++)
		ret.push_back(u(e));

	return ret;
}

int main()
{
	for (auto n : bad_ranVec())
		cout << n << ' ';
	cout << endl;

	system("pause");
	return 0;
}