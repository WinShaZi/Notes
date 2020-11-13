#include <iostream>

template <typename T>
class Test
{
    // 当T为类时，可以不加class(之前firend class)，当T不为类时，忽略此声明
    friend T;
private:
    void Show()
    {
        std::cout << "Test" << std::endl;
    }
};

class A
{
public:
    void Show()
    {
        Test<A> ca;

        ca.Show();
        std::cout << "A" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    A a;

    /**
     * 输出
     * Test
     * A
     */
    a.Show();

    return 0;
}
