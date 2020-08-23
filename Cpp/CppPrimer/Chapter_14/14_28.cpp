/*

StrBlobPtr & StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr & StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr & StrBlobPtr::operator+(size_t n) const
{
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr & StrBlobPtr::operator-(size_t n) const
{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

*/