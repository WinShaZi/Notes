#include <iostream>

using namespace std;

int main()
{
	float i, j;

	while (cin >> i >> j )
	{
		try
		{
			if (j < 0.000001 && j > -0.000001)
				throw runtime_error("j == 0");
		}
		catch(const std::exception& e)
		{
			cerr << e.what() << endl;
			cout << "Continue y / n : ";

			char ch;
			
			if (cin >> ch && tolower(ch) == 'y')
				continue;
			break;
		}
		cout << i / j << endl;
	}
	system("pause");
	return 0;
}