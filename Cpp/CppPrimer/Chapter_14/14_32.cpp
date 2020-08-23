/*

class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) { }

    StrBlobPtr& operator *() const;
    StrBlobPtr* operator->() const;

private:
    StrBlobPtr* pointer = nullptr;
};

StrBlobPtr & StrBlobPtr_pointer::operator *() const
{
    return *pointer;
}

StrBlobPtr * StrBlobPtr_pointer::operator ->() const
{
    return pointer;
}

*/