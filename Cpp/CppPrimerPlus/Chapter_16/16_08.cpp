#include <iostream> 
#include <string>
#include <list>
#include <algorithm>

using namespace std;
void show(string& s);

int main()
{
	list<string> Mat;
	cout << "-----------Mat's friends-----------" << endl;
	cout << "Input a name, and (quit to quit):" << endl;
	string temp1;
	getline(cin, temp1);
	while (temp1 != "quit")
	{
		Mat.push_back(temp1);
		cout << "Input a name, and (quit to quit):" << endl;
		getline(cin, temp1);
	}
	Mat.sort();
	cout << "Here are Mat's friends : " << endl;
	for_each(Mat.begin(), Mat.end(), show);
	cout << endl;

	list<string> Pat;
	cout << "-----------Pat's friends-----------" << endl;
	cout << "Input a name, and (quit to quit):" << endl;
	string temp2;
	getline(cin, temp2);
	while (temp2 != "quit")
	{
		Pat.push_back(temp2);
		cout << "Input a name, and (quit to quit):" << endl;
		getline(cin, temp2);
	}
	Pat.sort();
	cout << "Here are Pat's friends : " << endl;
	for_each(Pat.begin(), Pat.end(), show);
	cout << endl;

	cout << "--------------friends--------------" << endl;
	Mat.splice(Mat.end(), Pat);
	Mat.sort();
	Mat.unique();
	cout << "All friends : " << endl;
	for_each(Mat.begin(), Mat.end(), show);

	system("pause");
	return 0;
}

void show(string& s)
{
	cout << "friend'name : " << s << endl;
}