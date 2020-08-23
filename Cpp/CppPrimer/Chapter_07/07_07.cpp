/*
int main()
{
    Sales_data total;

​   if (read(cin, total)) 
    {
        Sales_data trans;

​       while (read(cin, trans)) 
        {
​           if (total.isbn() == trans.isbn()) 
            {
                total.combine (trans);
​            }
​            else 
            {
                print(cout, total);
​               total = trans;
​            }

​       }
​       print(cout, total);
    }
​    else 
    {
​       std::cerr << "No data" << endl;​
        return -1;
    }
    
    system("pause");
    return 0;
}

*/