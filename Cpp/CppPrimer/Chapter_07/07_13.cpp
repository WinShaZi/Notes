/*

{
    Sales_data total (cin);

​    if (cin)
    {
        Sales_data trans(cin);

​        do
        {
​            if (total.isbn() == trans.isbn()) 
            {
​                total.combine (trans);
​            }
​            else 
            {
​                print(cout, total);
​                total = trans;
​            }

​        } while (read(cin, trans));

​        print(cout, total);
​    }
​    else 
    {
​        std::cerr << "No data" << endl;

        return -1;
​    }
}

*/