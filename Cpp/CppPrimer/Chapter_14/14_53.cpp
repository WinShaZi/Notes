/*

内置的operator+(int, double)是可行的，而3.14可以转换为int，然后再转换为SmallInt，
所以SmallInt的成员operator+也是可行的。两者都需要进行类型转换，所以会产生二义性。改为：

double d = s1 +SmallInt(3.14);

*/