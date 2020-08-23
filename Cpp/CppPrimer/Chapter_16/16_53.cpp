#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

template<typename T> 
ostream &print(ostream &os, const T &t)
{  
    return os << t << endl;
}

template <typename T, typename...Args>
ostream & print(ostream &os, const T &t, const Args &...rest)
{
    os << t << ' ';
	return print(os, rest...);
}
 
int main()
{
	print(cout, 1, "A", 'b');

	system("pause");
    return 0;
}