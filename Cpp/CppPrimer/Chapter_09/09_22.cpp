/*

    vector<int> iv  = {1, 3, 5};
    iv.reserve(5);              //必须要又足够的容量，否则size为3，插入一个元素之后size超出，iter就会失效，指向未知地址。
    int some_val = 1;

    vector<int>::iterator iter = iv.begin(),
                    mid = iv.begin() + iv.size()/2;

    while(iter != mid) 
    {
        if (*iter == some_val) 
        {
            mid = iv.insert(iter, 2 * some_val);    //insert操作要接收返回的迭代器，如果赋给iter，则iter和mid永远不会相等，
        }                                           //因为mid也会随之改变。mid接收，mid就和iter都指向首元素了
        else 
        {
            mid --;
        }
    }

*/