/*

ld = si + ld;具有二义性，调用1需将si转换为LongDouble，ld转换为SmallInt。

调用2需要将si转换为LongDouble，ld转换为double。

ld = ld + si;精确匹配LongDouble operator+ (const SmallInt&);

若调用LongDouble operator+(LongDouble&, double);还需将si转换为double

*/