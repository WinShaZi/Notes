#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

class Repository
{
private:
    std::queue<int> m_queue;
    std::mutex m_mtx;
    size_t m_maxSize;
    std::condition_variable m_cv; // 只能与std::unique_lock进行绑定
    bool isFull;

public:
    Repository(const size_t &size = 10)
    {
        m_maxSize = size < 10 ? 10 : size;
        isFull = false;
    }

    ~Repository() {}

    void PushBack()
    {
        while (true)
        {
            std::unique_lock<std::mutex> uLock(m_mtx);

            /**
             * m_cv.wait()          阻塞等待通知和谓词为真
             * m_cv.wait_for()      在指定的时段内未等到通知和谓词为真，返回false
             * m_cv.wait_until()    在指定时间点之气那未未等到通知和谓词为真，返回false
             */
            m_cv.wait(uLock, [&] { return m_queue.empty(); });

            while (m_queue.size() <= m_maxSize)
            {
                int value = random();
                std::cout << "push " << value << std::endl;
                m_queue.push(value);
            }
            std::cout << "Repository is full" << std::endl;
            uLock.unlock();

            /**
             * m_cv.notify_one()    随机通知任意一个处于等待阶段的线程 
             * m_cv.notify_all()    通知所有处于等待阶段的线程
             */
            m_cv.notify_all();
        }
    }

    void PopFront()
    {
        while (true)
        {
            std::unique_lock<std::mutex> uLock(m_mtx);

            m_cv.wait(uLock, [&] { return m_queue.size() >= m_maxSize; });

            while (!m_queue.empty())
            {
                std::cout << "pop " << m_queue.front() << std::endl;
                m_queue.pop();
            }
            std::cout << "Repository is empty" << std::endl;
            uLock.unlock();
            m_cv.notify_all();
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
