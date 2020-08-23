/*

int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);

    if (ifs) 
    {
        Sales_data total;
        if (read(ifs, total)) 
        {     // ifstream继承与istream，因此这里可以直接使用文件流。
            Sales_data trans;
            while (read(ifs, trans)) 
            {
                if (total.isbn() == trans.isbn()) 
                {
                    total.combine(trans);
                }
                else 
                {
                    print(cout, total) << endl;
                    total = trans;
                }
            }
            print(cout, total) << endl;
        }
        else 
        {
            cout << "No data?" << endl;
        }
    }
    else 
    {
        cout << "file name error?" << endl;
    }
    
    system("pause");
    return 0;
}

*/