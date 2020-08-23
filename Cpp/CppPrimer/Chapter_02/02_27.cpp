//a : int i = -1, &r = i;

//b : int i2; int *const p2 = &i2;

//d : int i2; const int *const p3 = &i2;

//e : int i2; const int *pl = &i2;

//f : int i2; const int &r2 = i2;

//const int 必须初始化
//cosnt int & 必须引用一个值，可以不初始化
//const int * 可以不指向任何值，如值向的值可以不初始化
//int *const 必须指向一个值，可以不初始化
//const int *const 必须指向一个值，可以不初始化