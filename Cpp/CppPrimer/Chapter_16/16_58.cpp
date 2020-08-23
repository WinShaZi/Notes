/*

template <typename T, typename...Args>
inline void Vec<T>::emplace_back( Args&& ...args )
{
    chk_n_alloc();
    alloc.construct( first_free++, std::forward<Args>(args)... );
}

*/