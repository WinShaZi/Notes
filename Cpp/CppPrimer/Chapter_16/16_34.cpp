/*

(a) compare( "hi", "world" );

不合法。"hi"的类型是const char[3], "world"的类型是const char[6]，两个形参的类型不相同

(b) compare( "bye", "dad" );

合法。两个实参的类型都是const char[4]。能够调用compare

*/