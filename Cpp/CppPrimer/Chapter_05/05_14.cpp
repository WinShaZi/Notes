#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count_temp = 0;
	int count_now = 1;
	int count_max = 0;
	string str_temp;
	string str_prev;
	string str_max;

	while (cin >> str_temp)
	{
		count_temp++;
		if (str_temp == str_prev)
		{
			count_now += count_temp;
			if (count_now > count_max)
			{
				count_max = count_now;
				str_max = str_temp;
			}
		}
		else
			count_now = 1;
			
		count_temp = 0;
		str_prev = str_temp;
	}

	cout << str_max << " : " << count_max << endl;

	system("pause");
	return 0;
}