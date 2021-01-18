#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

class Repository
{
private:
    std::queue<int> m_queue;
    std::mutex m_mtxOne;
    std::mutex m_mtxTwo;
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
            /**
             * 阻塞至同时获取两个锁，且当只有成功获取m_mtxOne时才会获取m_mtxTwo
             * 当获取不到m_mtxTwo时，立马释放m_mtxOne，避免产生死锁
             */
            std::lock(m_mtxOne, m_mtxTwo);
            std::lock_guard<std::mutex> uLockOne(m_mtxOne, std::adopt_lock);
            std::lock_guard<std::mutex> uLockTwo(m_mtxTwo, std::adopt_lock);

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
        }
    }

    void PopFront()
    {
        while (true)
        {
            /**
             * 非阻塞形式尝试加锁，获取不到m_mtxOne时，返回false
             * 当获取m_mtxOne时，未能获取m_mtxTwo，则立马释放m_mtxOne，返回false
             */
            if (std::try_lock(m_mtxOne, m_mtxTwo))
            {
                if (!m_queue.empty())
                {
                    std::cout << "pop " << m_queue.front() << std::endl;
                    m_queue.pop();
                }
                else
                {
                    std::cout << "Repository is empty" << std::endl;
                }

                m_mtxOne.unlock();
                m_mtxTwo.unlock();
            }
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
