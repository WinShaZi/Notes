#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
	map<string, int> msi = { { "one", 1 } };

    ++msi["one"];
    cout << msi["one"] << endl;
	
	system("pause");
	return 0;
} 

//可以使用key_type对其执行下标操作，mapped_type为其返回类型