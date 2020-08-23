/*

{
    Sales_item total;
    istream_iterator<Sales_item> in_iter(cin);
    istream_iterator<Sales_item> eof;
    vector<Sales_item> sale_vec;

    while (in_iter != eof) {
        sale_vec.push_back(*in_iter++);
    }

    sort(sale_vec.begin(), sale_vec.end(), compareIsbn);
    Sales_item sale_sum;
    for (auto beg = sale_vec.cbegin(), end = beg; beg != sale_vec.cend(); beg = end) {
        end = find_if(beg, sale_vec.cend(), [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
        cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
    }
}

*/