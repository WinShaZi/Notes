
//1.1  
//using exercise::ivar;//错误，与全局变量ivar冲突，多次声明  
//using exercise::dvar;  
//using exercise::limi;  
//  
//void manip()  
//{  
//  double dvar = 3.1416;//覆盖using声明的dvar  
//  int iobj = limi + 1;  
//  ++ivar;  
//  ++::ivar;  
//}  
  
  
//1.2  
//void manip()  
//{  
//  using exercise::ivar;//隐藏全局变量  
//  using exercise::dvar;  
//  using exercise::limi;  
//  double dvar = 3.1416;//错误，多重定义，多次初始化，当前dvar对象已经可见  
//  int iobj = limi + 1;  
//  ++ivar;//exercise的ivar  
//  ++::ivar;//全局变量  
//}  
  
//2.1  
//using namespace exercise;  
//void manip()  
//{  
//  double dvar = 3.1416;//覆盖using声明的dvar  
//  int iobj = limi + 1;  
//  ++ivar;//错误，不明确,二义性,二者都可见  
//  ++::ivar;  
//}  
  
//2.2  
//void manip()  
//{  
//  using namespace exercise;  
//  double dvar = 3.1416;//覆盖using声明的dvar  
//  int iobj = limi + 1;  
//  ++ivar;//错误，不明确,二义性,二者都可见  
//  ++::ivar;  
//}