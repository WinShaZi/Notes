/*

namespace p  
{  
    void compute();//不可行  
    void compute(const void *);//可行,0->NULL  
}  
using p::compute;  
void compute(int);//可行,最佳匹配  
void compute(double, double = 1.1);//可行,int->double  
void compute(char*, char* = 0);//可行,0->NULL  
  
void f()  
{  
    compute(0);//与compute(int)版本最佳匹配  
}

*/