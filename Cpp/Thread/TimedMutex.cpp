#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

class Repository
{
private:
    std::queue<int> m_queue;
    std::timed_mutex m_tMtx;
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
             * m_tMtx.try_lock_until() 阻塞到一个时间点，没有拿到锁立即返回false
             * m_tMtx.try_lock_for() 阻塞一段时长，没有拿到锁立即返回false
             */
            if (m_tMtx.try_lock_for(std::chrono::milliseconds(500)))
            {

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

                m_tMtx.unlock();
            }
        }
    }

    void PopFront()
    {
        while (true)
        {
            // 不阻塞，拿不到锁立即返回false
            if (m_tMtx.try_lock())
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

                m_tMtx.unlock();
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
