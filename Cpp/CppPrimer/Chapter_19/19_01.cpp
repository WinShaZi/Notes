#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <new>

using namespace std;

void * operator new(size_t n)
{  
    if (void *mem = malloc(n))  
        return mem;  
    else  
        throw std::bad_alloc();  
}  

void operator delete(void *mem) noexcept
{
    free(mem);  
}

int main()  
{
    int *a = new int(486);

    cout << a << " " << *a << endl;  
    delete a;

    system("pause");  
    return 0;  
}