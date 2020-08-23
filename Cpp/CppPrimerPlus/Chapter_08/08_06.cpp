#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(const T ar[], int n);
const char* length(const char* ch[], int n);

int main()
{
	int iar[6] = { 1, 2 , 6, 5, 3, 4 };
	double dar[4] = { 6.6, 4.4, 7.7, 3.3 };
	const char* ch[5];
	
	ch[0] = "Are you OK?";
	ch[1] = "I'm Ok.";
	ch[2] = "Who are you?";
	ch[3] = "I am I.";
	ch[4] = "You are you.";
	cout << "Int max = " << maxn(iar, 6) << endl;
	cout << "Double max = " << maxn(dar, 4) << endl;
	cout << "string max = " << length(ch, 5) << endl;

	system("pause");
	return 0;
}

template <typename T>
T maxn(const T ar[], int n)
{
	T temp = ar[0];

	for (int i = 0; i < n; i++)
		if (ar[i] > temp)
			temp = ar[i];

	return temp;
}

const char* length(const char* ch[], int n)
{
	unsigned max = strlen(ch[0]);
	const char* temp = ch[0];

	for (int i = 0; i < n; i++)
		if (strlen(ch[i]) > max)
		{
			max = strlen(ch[i]);
			temp = ch[i];
		}

	return temp;
}