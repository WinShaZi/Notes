#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct out_of_stock :public runtime_error  
{  
    explicit out_of_stock(const string &s) :runtime_error(s) { }  
};  
  
struct isbn_mismatch :public logic_error  
{  
    explicit isbn_mismatch(const string &s) :logic_error(s) { }  
    isbn_mismatch(const string &s, const string &ls, const string &rs)  
        :logic_error(s), left(ls), right(rs) { }  
    string left;  
    string right;  
};

int main()
{
	
 
	system("pause");
	return 0;
}