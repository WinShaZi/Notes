# 简单启动线程

import threading
import time


def Run(label, n):
    for i in range(n):
        print(label + ' ' + str(int(time.time())))
        time.sleep(1)


t1 = threading.Thread(target=Run, args=('t1', 3,))
t2 = threading.Thread(target=Run, args=('t2', 5,))

t1.start()
t2.start()
