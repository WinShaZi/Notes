#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>  
string debug_rep(T *t)
{  
	cout << "T *t" << endl;
    ostringstream ret;  
    ret << t;  
    return ret.str();  
}

template<>  
string debug_rep(char *t)  
{  
	cout << "char *t" << endl;
    return string(t);  
}

template<>  
string debug_rep(const char *t)  
{  
	cout << "const char *t" << endl;
    return string(t);  
}

int main()
{
	char *c = "char";

	cout << debug_rep(c) << endl;
	cout << endl;
	cout << debug_rep("string") << endl;

	system("pause");
	return 0;
}