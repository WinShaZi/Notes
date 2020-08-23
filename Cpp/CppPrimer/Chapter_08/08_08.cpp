/*

int main(int argc, char** argv)
{
    ifstream ifs(argv[1]);
    ofstream ofs(argv[2], ofstream::app);

    if (ifs) 
    {
        Sales_data total;
        if (read(ifs, total)) 
        {
            Sales_data trans;
            while (read(ifs, trans)) 
            {
                if (total.isbn() == trans.isbn()) 
                {
                    total.combine(trans);
                }
                else 
                {
                    print(ofs, total) << endl;
                    total = trans;
                }
            }
            print(ofs, total) << endl;
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