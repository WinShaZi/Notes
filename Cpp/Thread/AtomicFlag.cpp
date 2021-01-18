#include <iostream>
#include <thread>
#include <atomic>
#include <queue>

class Repository
{
private:
    std::queue<int> m_queue;
    // 利用std::mtomic_flag完成自旋锁
    std::atomic_flag m_flag;
    size_t m_maxSize;

public:
    Repository(const size_t &size = 10) : m_flag(ATOMIC_FLAG_INIT)
    {
        m_maxSize = size < 10 ? 10 : size;
    }

    ~Repository() {}

    void PushBack()
    {
        while (true)
        {
            // 返回m_flag当前的值后将其置为true
            while (m_flag.test_and_set())
                ;

            if (m_queue.size() < m_maxSize)
            {
                int value = rand();
                std::cout << "push " << value << std::endl;
                m_queue.push(value);
            }
            else
            {
                std::cout << "Repository is full" << std::endl;
            }

            // 将其置为false
            m_flag.clear();
        }
    }

    void PopFront()
    {
        while (true)
        {
            while (m_flag.test_and_set())
                ;

            if (!m_queue.empty())
            {
                std::cout << "pop " << m_queue.front() << std::endl;
                m_queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            m_flag.clear();
        }
    }
};

int main(int argc, char const *argv[])
{
    Repository repo(1024);

    std::thread pushThread(&Repository::PushBack, &repo);
    std::thread popThread(&Repository::PopFront, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
