# 信号量

import threading
import time


def Run(label, semaphore):
    semaphore.acquire()
    print(label)
    time.sleep(1.5)
    semaphore.release()


# 当前活跃线程
maxThread = threading.active_count()
# 最多允许5个线程同时运行
semaphore = threading.BoundedSemaphore(5)

for i in range(20):
    t = threading.Thread(target=Run, args=('t{:d}'.format(i), semaphore))
    t.start()
while threading.active_count() - maxThread > 1:
    # print(threading.active_count())
    pass
else:
    print('end')
