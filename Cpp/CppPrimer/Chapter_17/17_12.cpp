#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <bitset>
#include <numeric>
#include <ctime>

using namespace std;

const int SIZE = 100;

template <unsigned N>
class Answer
{
private:
	bitset<N> bt;
	void check(const unsigned u, const string &st)
	{
		if (u > bt.size())
			throw out_of_range(st);
	}
public:
	Answer()
	{
		for (int i = 0; i < N; i++)
			bt[i] = rand() % 2;
	}
	bool find(const unsigned u, const bool b)
	{
		check(u, "out of range");
		cout << "No. " << u << " answer is " << bt[u - 1] << endl;
		cout << "Your answer " << b << " is ";
		return bt[u - 1] == b;
	}
	unsigned grade(const bitset<N> bi)
	{
		unsigned count = 0;

		bitset<N> temp = bi ^ bt;
		temp.flip();

		return temp.count();
	}
	void show() const
	{
		for (int i = 0; i < N; i++)
		{
			cout << bt[i];
			if (i % 20 == 19)
				cout << endl;
		}
		cout << endl;
	}
};

void show(const bitset<SIZE> bi)
{
	for (int i = 0; i < 10; i++)
	{
		cout << bi[i];
		if (i % 20 == 19)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	srand(unsigned(time(0)));

	Answer<SIZE> an;
	bitset<SIZE> bt;
	for (int i = 0; i < 10; i++)
		bt[i] = rand() % 2;

	an.show();
	cout << (an.find(rand() % SIZE, 1) ? "true" : "false") << endl << endl;

	show(bt);
	cout << "Grade : " << an.grade(bt) << endl;

	system("pause");
	return 0;
}