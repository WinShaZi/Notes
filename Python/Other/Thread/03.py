# 守护线程

import threading
import time


def Run(label, n):
    for i in range(n):
        print(label + ' ' + str(int(time.time())))
        time.sleep(1)


t = threading.Thread(target=Run, args=('t1', 3,))

# 在start前设置，当主线程结束t随之结束
t.setDaemon(True)

t.start()

print('end')
