/*


template<typename T>  
Blob<T>::Blob() try:data(std::make_shared<std::vector<T>>()) { }
catch (const std::bad_alloc &e) 
{  
    std::cerr << e.what() << std::endl;  
}


*/