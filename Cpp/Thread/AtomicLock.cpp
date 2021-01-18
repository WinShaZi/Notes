#include <iostream>
#include <thread>
#include <atomic>
#include <queue>

class Repository
{
private:
    std::queue<int> m_queue;
    // 利用原子操作特性做成类似互斥锁
    std::atomic_bool m_amc;
    size_t m_maxSize;

public:
    Repository(const size_t &size = 10)
    {
        m_maxSize = size < 10 ? 10 : size;
        m_amc.store(false);
    }

    ~Repository() {}

    void PushBack()
    {
        while (true)
        {
            // 获取其值，当其值为false时，进入下一轮循环
            if (!m_amc.load())
            {
                continue;
            }

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

            // 设置其值
            m_amc.store(false);
        }
    }

    void PopFront()
    {
        while (true)
        {
            if (m_amc.load())
            {
                continue;
            }

            if (!m_queue.empty())
            {
                std::cout << "pop " << m_queue.front() << std::endl;
                m_queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            m_amc.store(true);
        }
    }
};

int main(int argc, char const *argv[])
{
    Repository repo;

    std::thread pushThread(&Repository::PushBack, &repo);
    std::thread popThread(&Repository::PopFront, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
