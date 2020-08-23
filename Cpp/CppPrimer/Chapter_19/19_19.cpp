/*

vector<Sales_data>::iterator largerThanD(vector<Sales_data>& vec, double d) 
{
    double d = 0;
    auto fn = mem_fn(&Sales_data::avg);
    return find_if(vec.begin(),vec.end(),[&](string&s){return fn(s) > d;}
}

*/