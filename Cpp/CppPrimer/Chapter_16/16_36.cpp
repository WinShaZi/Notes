/*

(a)f1( p1, p2 );
合法。T 的类型为int*

(b)f2( p1, p2 );

合法。T1 T2的类型都是int*

(c)f1( cp1, cp2 );

合法。T的类型为const int *

(d)f2( cp1, cp2 );

合法。T1 T2的类型都是const int*

(e)f1( p1, cp1 );

合法。T的类型是const int* //（p1先进行类型转换再传递给第一个形参）

非法。T的类型无论推断为int*还是const int*都无法匹配调用。

(f)f2( p1, cp1 );

合法。T1的类型是int*, T2的类型是const int*

*/