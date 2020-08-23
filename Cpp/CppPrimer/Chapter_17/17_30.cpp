#include <iostream>
#include <string>
#include <vector>
#include <random>
 
using namespace std;

vector<unsigned> bad_ranVec(unsigned i, unsigned minimum, unsigned maximum)
{
	static default_random_engine e(i);
	static uniform_int_distribution<unsigned> u(minimum, maximum);
	vector<unsigned> ret;

	for (size_t i = 0; i < 10; i++)
		ret.push_back(u(e));

	return ret;
}

int main()
{
	unsigned i;
	unsigned maximum;
	unsigned minimum;

	cout << "Input a three unsigned int : ";
	cin >> i >> minimum >> maximum;

	for (auto n : bad_ranVec(i, minimum, maximum))
		cout << n << ' ';
	cout << endl;

	system("pause");
	return 0;
}