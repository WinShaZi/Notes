# 创建线程类

import threading
import time


class MyThread(threading.Thread):
    def __init__(self, label, n):
        super().__init__()
        self.label = label
        self.n = n

    # 重写基类run方法
    def run(self):
        for i in range(self.n):
            print(self.label + ' ' + str(int(time.time())))
            time.sleep(1)


t1 = MyThread('t1', 3)
t2 = MyThread('t2', 5)

t1.start()
t2.start()
