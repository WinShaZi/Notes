int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;

//(int) a
//(int) b
//(int) c
//(int &) d;