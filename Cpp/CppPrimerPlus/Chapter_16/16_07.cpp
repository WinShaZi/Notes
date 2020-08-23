#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> Lotto(int m, int n);
void show(int n) { cout << n << " "; }

int main()
{
	srand(unsigned(time(0)));
	vector<int> winner;
	winner = Lotto(51, 6);

	cout << "Diaplsy the random number : " << endl;
	for_each(winner.begin(), winner.end(), show);
	cout << endl;

	system("pause");
	return 0;
}

vector<int> Lotto(int m, int n)
{
	vector<int> temp;

	for (int i = 1; i <= m; i++)
	{
		temp.push_back(i);
	}
	random_shuffle(temp.begin(), temp.end());
	vector<int>::iterator last;
	last = (temp.begin(), temp.begin() + n);
	temp.erase(last, temp.end());

	return temp;
}