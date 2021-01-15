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
            // 构造时加锁，析构时解锁，可以转移所有权
            std::unique_lock<std::mutex> uLock(m_mtx);

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

            // 提前解锁
            uLock.unlock();
            sleep(1);
        }
    }

    void PopFront()
    {
        while (true)
        {
            /**
             * std::defer_lock      不获得互斥的所有权
             * try_to_lock          尝试获得互斥的所有权而不阻塞
             * adopt_lock           假设调用方线程已拥有互斥的所有权
             */
            std::unique_lock<std::mutex> uLock(m_mtx, std::defer_lock);

            // 此时加锁
            uLock.lock();

            if (!m_queue.empty())
            {
                std::cout << "pop " << m_queue.front() << std::endl;
                m_queue.pop();
            }
            else
            {
                std::cout << "Repository is empty" << std::endl;
            }

            // 此时解锁
            uLock.unlock();

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
