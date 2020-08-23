////list和forward_list的迭代器不支持加减操作，因为链表的内存不连续，无法通过加减操作来寻址

/*

    list<int> ilist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto iter = ilist.begin();
    while (iter != ilist.end()) {
        if (*iter % 2) {
            iter = ilist.insert(iter, *iter);
            advance(iter, 2);
        } else {
            iter = ilist.erase(iter);
        }
    }


    forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto iter = flst.begin();
    auto prev = flst.before_begin();
    while (iter != flst.end()) 
    {
        if (*iter % 2) 
        {
            iter = flst.insert_after(prev, *iter);
            advance(prev, 2);
            advance(iter, 2);       
        } 
        else 
        {
            iter = flst.erase_after(prev);
        }
    }

*/