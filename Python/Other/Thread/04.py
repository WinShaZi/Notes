# 等待线程

import threading
import time


def Run(label, n):
    for i in range(n):
        print(label + ' ' + str(int(time.time())))
        time.sleep(1)


t = threading.Thread(target=Run, args=('t1', 3,))

t.start()

# 主线程等待t执行完毕
t.join()

print('end')
