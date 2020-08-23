#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    { 
        cerr << "Too few paramaters" << endl;
        exit(1);
    }

    string st;

    for (int i = 0; i < argc - 1; i++)
        st += argv[i];

    cout << st << endl;

    system("pause");
	return 0;
}