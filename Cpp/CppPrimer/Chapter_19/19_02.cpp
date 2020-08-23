/*

void * operator new(size_t n)
{  
    if (void *mem = malloc(n))  
        return mem;  
    else  
        throw std::bad_alloc();  
}  

void operator delete(void *mem) noexcept
{
    free(mem);  
}

*/