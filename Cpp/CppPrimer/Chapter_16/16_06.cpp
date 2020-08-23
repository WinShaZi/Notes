#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


template<typename T, unsigned N>
const T* begin(const T(&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
const T* end(const T(&arr)[N])
{
	return arr + N;
}

template<typename T, unsigned N>
void print(const T(&arr)[N])
{
	for (auto it = begin(arr); it != end(arr); it++)
		cout << *it << endl;
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9 };
	print(arr);

	system("pause");
	return 0;
}