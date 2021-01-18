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

    void PushBackTry()
    {
        while (true)
        {
            // 尝试获取锁，当获取到则返回真，未获取到则返回假
            if (m_mtx.try_lock())
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

                m_mtx.unlock();
            }
        }
    }

    void PopFrontTry()
    {
        while (true)
        {
            if (m_mtx.try_lock())
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

                m_mtx.unlock();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Repository repo;

    std::thread pushThread(&Repository::PushBackTry, &repo);
    std::thread popThread(&Repository::PopFrontTry, &repo);

    pushThread.join();
    popThread.join();

    return 0;
}
