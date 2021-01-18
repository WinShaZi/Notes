#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

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
            // 若获得锁便继续往下执行，若未获得锁便阻塞于此
            m_mtx.lock();

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

            // lock()之后必须解锁，否则该锁将被持续锁定
            m_mtx.unlock();
        }
    }

    void PopFront()
    {
        while (true)
        {
            m_mtx.lock();

            if (!m_queue.empty())
            {
                std::cout << "pop " << m_queue.front() << std::endl;
                m_queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            m_mtx.unlock();
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
