/*

a : 错误，不能连续声明模板参数 改为：template<typename T,typename U,typename V> void f1(T,U,V);
b : 错误，模板参数名不能作为变量名 改为：template<typename T> T f2(T &);
c : 错误，内联声明位置错误 改为：template<typename T> inline T foo(T,unsigned int *);
d : 错误，缺少返回类型 改为：template<typename> T f4(T,T);
e : 错误，模板参数将覆盖外层的Ctype 改为：typedef char C;或者是template<typename C> C f5(C a);

*/