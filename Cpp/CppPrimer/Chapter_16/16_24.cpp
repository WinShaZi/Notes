#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iterator>


using namespace std;

template<typename T> class Blob
{
public:
	template<typename IT> Blob(IT &, IT &);
};

template<typename T>
template<typename IT> Blob<T>:: Blob(IT &a, IT &b):data(make_shared<vector<T>>(a.b)) { }


int main()
{
	
	system("pause");
	return 0;
}