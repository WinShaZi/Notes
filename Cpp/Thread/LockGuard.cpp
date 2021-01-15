#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>

class Repository
{
private:
    std::queue<int> m_queue;
    std::mutex m_mtx;
    size_t m_maxSize;

public:
    Repository(const size_t &size = 10)
    {
        m_maxSize = size < 10 ? 10 : size;
    }

    ~Repository() {}

    void PushBack()
    {
        while (true)
        {
            {
                // 在构造时进行加锁，在析构时进行解锁，不可以中途解锁
                std::lock_guard<std::mutex> gLock(m_mtx);

                if (m_queue.size() < m_maxSize)
                {
                    int value = random();
                    std::cout << "push " << value << std::endl;
                    m_queue.push(value);
                }
                else
                {
                    std::cout << "Repository is full" << std::endl;
                }
            }
            sleep(1);
        }
    }

    void PopFront()
    {
        while (true)
        {
            {
                std::lock_guard<std::mutex> gLock(m_mtx);

                if (!m_queue.empty())
                {
                    std::cout << "pop " << m_queue.front() << std::endl;
                    m_queue.pop();
                }
                else
                {
                    std::cout << "Repository is empty" << std::endl;
                }
            }
            sleep(1);
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
