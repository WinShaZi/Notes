#include <iostream>
#include <string>
#include <regex>

	using namespace std;

int main()
{
	try 
	{
		regex reg("[^cei");
	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
 
	system("pause");
	return 0;