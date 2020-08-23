/*

g(42); f(42);

调用g( T ), T推断为int；

调用f( T ), T推断为int



g(p); f( p );

①f(T). T推断为int*。不需要类型转换

②f( const T* ). T推断为int， 需要进行非指向const的指针向指向const的指针的转换

所以调用的是f(T)



g(ci); f( ci );

调用的是g( T )。T推断为int。顶层const 被忽略。

调用的是f( T )。T推断为int。顶层const 被忽略。



g( p2 )；f( p2 );

调用的是g( T* )。T推断为const int

调用的是f( const T*)。 T推断为int

*/