#include <iostream>
#include <thread>
#include <chrono>

class OneClass
{
public:
    template <typename T>
    void Print(const T &t)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << t << " " << &t << std::endl;
    }
};

template <typename T>
void Print(const T &t)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << t << " " << &t << std::endl;
}

int main(int argc, char const *argv[])
{
    int i = 10;
    OneClass one;

    Print<int>(i);

    std::thread t1(&OneClass::Print<int>, &one, i); // 传递成员函数
    std::thread t2(Print<int>, i);                  // 传递i的拷贝到线程
    std::thread t3(Print<int *>, &i);               // 传递指针，传递的是原始指针，传递unique_ptr需要使用std::move转移所有权
    std::thread t4(Print<int>, std::ref(i));        // 传递引用，避免拷贝

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
