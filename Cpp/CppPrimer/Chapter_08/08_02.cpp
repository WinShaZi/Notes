#include <iostream>

using namespace std;

istream &input(istream & is)
{
    string word;
    
    while (is >> word) 
	{
        cout << word << " ";
    }
    cout << endl;
    is.clear();

    return is;
}

int main()
{
	input(cin);

	system("pause");
	return 0;
}