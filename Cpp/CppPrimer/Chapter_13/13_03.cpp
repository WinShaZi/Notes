/*

拷贝StrBlob时，其shared_ptr成员的引用计数会增加。
拷贝StrBlobPtr，unique_ptr成员的引用计数不变，弱引用不增加计数器

*/