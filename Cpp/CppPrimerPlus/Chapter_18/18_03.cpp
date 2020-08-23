#include <iostream>

using namespace std;

long double sum_value()
{
	return 0;
}

template<typename T>
long double sum_value(const T& t)
{
	return t;
}

template<typename T, typename...Args>
long double sum_value(const T& t, const Args& ...args)
{
	return t + sum_value(args...);
}


int main()
{
	cout << "No parameters :　";
	cout << sum_value() << endl;
	cout << "Single parameter : ";
	cout << sum_value('y') << endl;
	cout << "Multiple parameters : ";
	cout << sum_value('a', 1, 'b', 2.3, '#') << endl;

	system("pause");
	return 0;
}