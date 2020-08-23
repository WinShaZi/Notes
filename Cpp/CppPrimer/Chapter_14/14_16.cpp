/*

// StrBlob
bool operator== (const StrBlob& lhs, const StrBlob& rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!= (const StrBlob& lhs, const StrBlob& rhs)
{
    return *lhs.data != *rhs.data;
}

// StrBlobPtr
bool operator== (const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!= (const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr != rhs.curr;
}

// StrVec
bool operator== (const StrVec& lhs, const StrVec& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    else {
        auto l_iter = lhs.begin();
        auto r_iter = rhs.begin();
        for (l_iter, r_iter; l_iter != lhs.end(); ++ l_iter, ++ r_iter) {
            if (*l_iter != *r_iter) {
                return false;
            }
        }
    }
    return true;
}

bool operator!= (const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

// String
bool operator== (const String& lhs, const String& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    else {
        auto l_iter = lhs.begin, r_iter = rhs.begin;
        for (l_iter, r_iter; l_iter!=lhs.end; ++l_iter, ++r_iter) {
            if (*l_iter != *r_iter) {
                return false;
            }
        }
    }
    return true;
}

bool operator!= (const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

*/