/*

StrBlobPtr &StrBlobPtr::operator++() 
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--() 
{
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) 
{
  StrBlobPtr ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) 
{
  StrBlobPtr ret = *this;
  --*this;
  return ret;
}

*/